var P_LOCAL_LEADERBOARD_KEY = 23;
var P_GLOBAL_LEADERBOARD_KEY = 24;
var P_NAME_KEY = 25;
var P_USER_ID_KEY = 26;
var P_ACCOUNT_TOKEN_KEY = 27;

var APP_MSG_READY_KEY = 5;
var APP_MSG_NAME_STR_KEY = 25;

var APP_MSG_LBE_OFFSET = 100;
var APP_MSG_LBE_DATETIME_UINT_KEY = 0;
var APP_MSG_LBE_SCORE_UINT32_KEY = 1;
var APP_MSG_LBE_LEVEL_UINT8_KEY = 2;
var APP_MSG_LBE_NAME_STR_KEY = 3;
var APP_MSG_LBE_NUM_ELEMENTS = 4;

function isStringBlank(str){
  return str === undefined || str === null || str.match(/^\s*$/) !== null;
}

Pebble.addEventListener("ready", function(e) {
  localStorage.removeItem(P_ACCOUNT_TOKEN_KEY);
  localStorage.removeItem(P_NAME_KEY);
  localStorage.removeItem(P_USER_ID_KEY);
  console.log("PebbleKit JS ready!");
  var accountToken = Pebble.getAccountToken();
  if (!isStringBlank(accountToken)) {
    localStorage.setItem(P_ACCOUNT_TOKEN_KEY, accountToken);
  }
  var appMessageJSON = {};
  appMessageJSON[APP_MSG_READY_KEY] = 1;
  Pebble.sendAppMessage(
    appMessageJSON,
    function(e) {
      console.log("Sending settings data...");
    },
    function(e) {
      console.log("Settings settings failed!");
    }
  );
});

Pebble.addEventListener("appmessage", function(e) {
  console.log("message from watch");
  var leaderboardJSON = [];
  // console.log(Object.keys(e.payload).length);
  // console.log(JSON.stringify(e.payload));
  for (var i = 0; i < Object.keys(e.payload).length; i++) {
    var payloadKey = Number(Object.keys(e.payload)[i]);
    if (payloadKey >= APP_MSG_LBE_OFFSET) {
      var LBEIndex = ((payloadKey - APP_MSG_LBE_OFFSET) / APP_MSG_LBE_NUM_ELEMENTS) >> 0; // >> to do int divide
      var LBEKey = (payloadKey - APP_MSG_LBE_OFFSET) % APP_MSG_LBE_NUM_ELEMENTS;
      if (leaderboardJSON[LBEIndex] === null || leaderboardJSON[LBEIndex] === undefined) {
        leaderboardJSON[LBEIndex] = {};
      }
      if (LBEKey == APP_MSG_LBE_DATETIME_UINT_KEY) {
        leaderboardJSON[LBEIndex].datetime = e.payload[payloadKey];
      } else if (LBEKey == APP_MSG_LBE_LEVEL_UINT8_KEY) {
        leaderboardJSON[LBEIndex].level = e.payload[payloadKey];
      } else if (LBEKey == APP_MSG_LBE_SCORE_UINT32_KEY) {
        leaderboardJSON[LBEIndex].score = e.payload[payloadKey];
      }
    }
  }

  console.log(JSON.stringify(leaderboardJSON));
  sync_with_server(leaderboardJSON);
});

function storage_get_user_id() {
  var userIdStored = Number(localStorage.getItem(P_USER_ID_KEY));
  if (userIdStored == null) {
    userIdStored = 0;
  }
  return userIdStored;
}

function storage_get_account_token() {
  var accountToken = Pebble.getAccountToken();
  if (isStringBlank(accountToken)) {
    accountToken = localStorage.getItem(P_ACCOUNT_TOKEN_KEY);
    if (isStringBlank(accountToken)) {
      accountToken = "";
    }
  } else {
    localStorage.setItem(P_ACCOUNT_TOKEN_KEY, accountToken);
  }
  return accountToken;
}

function flatten_server_LBE_JSON(serverJSON) {
  if (!isStringBlank(serverJSON.error)) {
    // server says error
    console.log(serverJSON.error);
  } else if (serverJSON.scores !== undefined && serverJSON.scores !== null) {
    // success
    // console.log("" + JSON.stringify(serverJSON));
    var appMessageJSON = {};
    for (var i = 0; i < serverJSON.scores.length; i++) {
      var offset = APP_MSG_LBE_OFFSET + APP_MSG_LBE_NUM_ELEMENTS*i;
      appMessageJSON[offset + APP_MSG_LBE_DATETIME_UINT_KEY] = serverJSON.scores[i].datetime;
      appMessageJSON[offset + APP_MSG_LBE_SCORE_UINT32_KEY] = serverJSON.scores[i].score;
      appMessageJSON[offset + APP_MSG_LBE_LEVEL_UINT8_KEY] = serverJSON.scores[i].level;
      appMessageJSON[offset + APP_MSG_LBE_NAME_STR_KEY] = serverJSON.scores[i].name;
    }
    if (serverJSON.name !== undefined && serverJSON.name !== null) {
      appMessageJSON[APP_MSG_NAME_STR_KEY] = serverJSON.name;
    }
    return appMessageJSON;
  }
  return null;
}

function sync_with_server(localLeaderboardJSON) {
  var xmlhttp=new XMLHttpRequest();
  xmlhttp.onreadystatechange = function() {
    console.log("recieved reply from server: " + xmlhttp.responseText);
    if (xmlhttp.readyState == 4 && xmlhttp.status == 200) {
      var responseJSON = JSON.parse(xmlhttp.responseText);
      var appMessageJSON = flatten_server_LBE_JSON(responseJSON);
      if (appMessageJSON !== null) {
        console.log(JSON.stringify(appMessageJSON));
        Pebble.sendAppMessage(appMessageJSON, function(e) {
          console.log("Success sending global leaderboard to watch");
        }, function(e) {
          console.log("Failure sending global leaderboard to watch");
        });
      }
    }
  };
  localLeaderboardJSON.account_token = storage_get_account_token();
  localLeaderboardJSON.id = storage_get_user_id();
  xmlhttp.open("GET","https://lit-tundra-7074.herokuapp.com/update_scores" +
    "?account_token=" + storage_get_account_token() + "&id=" + storage_get_user_id() + 
    "&scores=" + JSON.stringify(localLeaderboardJSON),true);
  xmlhttp.send();
}

Pebble.addEventListener("showConfiguration", function(e) {
  // Show config page
  var oldName = localStorage.getItem(P_NAME_KEY);
  if (oldName === null) {
    oldName = "";
  }
  Pebble.openURL("https://lit-tundra-7074.herokuapp.com/pebble_config.html" + 
                 "?account_token=" + storage_get_account_token() + "&id=" + storage_get_user_id() + "&name=" + oldName);
  // the server will attempt to match by account token first, failing that it will attempt to match by the stored user id
  // sending the old name to populate the name field.
});

Pebble.addEventListener("webviewclosed", function(e) {
  //Get JSON dictionary
  var configurationJSON = JSON.parse(decodeURIComponent(e.response));
  console.log("Configuration window returned: " + JSON.stringify(configurationJSON));

  var newUserId = configurationJSON.id;
  if (newUserId >= 0) {
    localStorage.setItem(P_USER_ID_KEY, newUserId);
  }

  localStorage.setItem(P_NAME_KEY, configurationJSON.name);

  var appMessageJSON = flatten_server_LBE_JSON(configurationJSON);
  if (appMessageJSON !== null) {
    console.log("sending " + JSON.stringify(appMessageJSON));

    //Send to Pebble, persist there
    Pebble.sendAppMessage(
      appMessageJSON,
      function(e) {
        console.log("Sending settings data...");
      },
      function(e) {
        console.log("Settings settings failed!");
      }
    );
  }
});


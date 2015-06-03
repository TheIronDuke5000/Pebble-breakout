//////////////////////////////////////
//         Pebble Breakout          //
//            Copyright             //
//      Iron Duke Industries        //
//           Will Cullen            //
//             May 2015             //
//////////////////////////////////////
/*
                                                                                             
         /-                                                                                  
         yd:                                                                                 
         .hm:                                                                                
          .ym/                                                                               
           `ym+                                                                              
            `sm+                                                                             
             `ymo                                                                            
              `yms`                            `                                             
               `ymy.                       -sysy+                                            
                `ymd-                  -osodmmdd+                                            
                 `smd-                omNmhdmmd-                                             
                  `sNdyo-..``       /yNmmmdNNN:                                              
                   oNNmmdhyyy+.     +mNmmNNNNo                                               
                   smNNNmmmNmdyso:. :mddmNNMNdo:`                                            
                   `+hhs:hNNmmddyys+/ddmmdhmNmmmh/                                           
                      `  `:::omddhyyhdmdyyyhyyhmh-                                           
                             .dhshddmNNmdmmdhyshho                                           
           `.                `s/ `-/hNmmNNmddhyydm-                                          
         `-dN/ss                    ymNNMMmdddhyhh.                                          
        -dNNMNMN` ``.--.`           hNNNNMNNmhysh:                                           
        sMMNMMMNsydmmNNNmo:`        yNmdmNMNNdysy:                                           
        yNNmmNNNmNNNMMMMMMMd/`     :mmmhhdmmmmmdhs/.`                                        
       /NMNdhdmddNNMMMMMNNNMMhyoooooNNMNmmNNNNNNNmmdy`                                       
      /NMMMMMMNNNNNMMMMMMMMMMMNmmNNdmNMMNNMNNMMNNNNm+`                                       
     +NMMMMMMNNNNNNMMMMMMMMMNmmMMMNdmNNMNmmdddmNmmmNNdys+-`                                  
    +NNNMMMNNMMMMMNMMMMMMMNmmMMMMNdshNNMMMNmmdhhyssyhdmmmNms:`                               
   +NNNNNNNMMMMMMMMMMMMNmmmMMMMMNmhoydmMMMNNNNNmdhyssyyhdmddNms:`                            
  /NNNMMNmNMMmdmNMNNNNNNMMMMMMMNmdssydmNMMNddhmdmNmhyhdmysdNNNMNmy/:/+os+++:.                
  +MNMMMMNNNdmNNmdNMMMMMMMMMMMMNNdysydmmmMmyoooshNNmNMMMNyhmNNNNMMMNNNNNMMMMNdo.             
   sMMMNmdmmmho: .dMMMMMMMMMMMMMMMMMMMMNdmNNmmmmmmNNMMMMMhsyNNNNMMMMMMmddmNMMMMMd/`          
   `omMmdhs/.     `+mMMMMMMMMNmMMNyhNNNmmmNMNNNNNNmNNNNNNhhmNMMMMMMMMMm`  `sMMMMMMm.         
     .+/-`          /NMMMMMMNmddmNyhNNmdNmmMNNNNNmmmNNmdhyyhNMMMMMMMMMMs    dMMMMMMd         
                     hNMMMMNmmmmmMNNMNNdhhhNMMNNNmddmhhhhdmmNMMMMMMMMMMm    sMMMMMMN.        
                    :NMMMNNNNNmmNMMMMMNmdddmmNNNNNmmmNNNMMMMMMMMMMMMMMNh    -NMMMMMM:        
                    -NNNNNmNNNMMMMMMMMMMMMMMMMMNNNNmdmNMMMMMMMMMMMMMMNN:     /MMMMMMm.       
                    `odmNNMMMMMMMMMMMMMMMMMMMMMMNmmdmmNMMMMMMMMMMMMMNNs       hMMMMMMh       
                      sNMMMMMNNNMMMMMMMMMMMMMMNNNNNhdNNMMMMMMMMMMMNNNs`       -NMMMMNo       
                      .oNNNNmmNNNMMMMMMMMMMMMNNNNmmmmNmMMMMMMMMMMNNN/          :ydhs:        
                   -ohddmNNNNNNMMMMMNNh+oo+++/.ymhdyssNMMMMMNMMMMMMm             `           
                  /NMMNNMMMMMNddhyo/..`        `.`.`  /MMMMMmNMMMMNy                         
                  /MMMMMMMMMh-``                      :MMMMMMmMMMMNm.                        
                  `dMMMMMMMd`                      `.+NMMMMMMmMMMMMNy                        
                   :NMMMMMMo                 `--:+ymNMMMMNdhodMMMMMN+                        
                    oMMMMMMm.          `   `smNMMMMMMMmh+-``sMMMMNm/                         
                    `mMMMMMMm-         +y.-dMMMNMNdy+:.   `yMMMMNy.                          
                     /NMMMMMMN+  `   :.sMmNMMMs-:.`     `:dMMMNh-                            
                      -+yNMNNMMhhdy: ymNMMMMMM/        -hNNMMd/`                             
                         /mNMMMMMMMN-.MMMMMMNy.      `sNMMMMy`                               
                          .:ohy/hmNNo.NMMMMM+     ``:yNMMMMh-...`                            
                                 ..-ymMMMMMMm+:+oyhmMNNMMMMNNNNmhso+:-.                      
                ``.-```````.:/oysoshNMMMMMMMMNNNNMMMMmNNNNNNNNNNNNmmmmm-                     
       `.--/+syydmNMNddmmmmNNNNNNNNNNNNNNNMMMNNNNNNNNmmmNmmNNNNNNNmmmdy.                     
    -oshmmmmmmmNNNNNNNNNNmNmmmNmNNNNNNNNNNNNNNNNNddNNmmmmmmddhys+/:-.                        
   `mNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNmmmmmmmddhhyso++//::-.``                                 
   .ymNNNNNmmmmmmmmdmmddddhhyysoo+//::-.``                                                   
      `........```                                                                           
                                                                                             
*/


#include <pebble.h>

#define MAX_NUM_POWERUP_DROPS 10  // maximum number of currently dropping powerups
#define MAX_NUM_LASER_FIRE 20     // maximum number of laser fire in the air
#define PADDLE_MAX_SPEED 8
#define HOLD_AIM_INC TRIG_MAX_ANGLE/0x30;
#define BALL_TIME_PER_DIST 12
#define POWERUP_TIME_PER_DIST 50
#define LASER_FIRE_TIME_PER_DIST 6

#define BOMB_BLAST_RADIUS 20

static Window *s_menu_window;
static SimpleMenuLayer *s_menu_layer;
static Layer *s_status_layer;
static SimpleMenuSection s_menu_section;
static SimpleMenuItem s_menu_items[2];
static Window *s_main_window;
static Layer *s_main_layer;
static TextLayer *s_text_layer;
static char s_text_layer_text[20];
static Layer *s_ball_layer;
static int16_t s_ball_dir_angle;
static PropertyAnimation *s_ball_animation;
static Layer *s_paddle_layer;
static int16_t s_paddle_velocity;
static Layer **s_block_layer_array;
static uint16_t s_num_blocks = 0;
static Layer *s_aim_layer;
static bool s_is_resume;
static Layer *s_powerup_layer_array[MAX_NUM_POWERUP_DROPS];
static PropertyAnimation *s_powerup_animation_array[MAX_NUM_POWERUP_DROPS];
static uint8_t s_num_powerup_drops = 0;
static uint8_t s_num_lives;
static uint8_t s_level;
static uint32_t s_score;
static GFont s_arcade_font_8;
static Layer *s_laser_fire_layer_array[MAX_NUM_LASER_FIRE];
static PropertyAnimation *s_laser_fire_animation_array[MAX_NUM_LASER_FIRE];
static uint8_t s_num_laser_fire = 0;

#define STATUS_LAYER_HEIGHT 16
#define SCORE_MAX_WIDTH 5
#define SCORE_BLOCK_KILL 1
#define SCORE_POWERUP_CATCH 10
#define SCORE_LEVEL_COMPLETE 100

#define s_powerup_frame  (GRect) { .origin = {(-48+16-6)/2, 0}, .size = {48, 12} }

#define s_powerup_text_frame (GRect) { .origin = {0, 0}, .size = {48, 8} }

#define s_powerup_pill_frame (GRect) { .origin = {24, 8}, .size = {6, 3} }

#define s_laser_fire_frame (GRect) { .origin = {-1, -5}, .size = {3, 5}}

#define PADDLE_ORIGIN_Y 144

#define P_PADDLE_KEY 0        // int for x value of origin of paddle layer
#define P_BALL_DATA_KEY 1     // array of 3 int16_t, [x, y, angle]    2 bytes per int16_t * 3 = 6 bytes 
#define P_POWERUP_KEY 2       // PowerupTypeEnum saved as an int
#define P_BLOCKS_DATA_KEY 4   // array of bytes with the same format as the file (HH XX YY) HH is the nubmer of hits remaining
#define P_LIVES_KEY 5
#define P_LEVEL_KEY 6
#define P_SCORE_KEY 7

#define PADDLE_WIDTH_STANDARD 30
#define PADDLE_WIDTH_SMALL 16
#define PADDLE_WIDTH_WIDE 60

uint32_t s_map_resource_array[] = {
  RESOURCE_ID_MAP1,
  RESOURCE_ID_MAP2
  // RESOURCE_ID_MAP3,
  // RESOURCE_ID_MAP4,
  // RESOURCE_ID_MAP5,
  // RESOURCE_ID_MAP6,
  // RESOURCE_ID_MAP7,
  // RESOURCE_ID_MAP8,
  // RESOURCE_ID_MAP9,
  // RESOURCE_ID_MAP10
};

typedef enum {
  WALL_VERT,
  WALL_HORZ,
  PADDLE_HIT,
  PADDLE_PHANTOM,
  IMMINENT_DEATH,
  DEATH,
  BLOCK_VERT,
  BLOCK_HORZ,
  NO_REFLECT
} BallReflectionTypeEnum;

typedef enum {
  HOLD = 0,
  LASER = 1,
  WIDE = 2,
  SMALL = 3,
  LIFE = 4,
  BOMB = 5,
  PLASMA = 6,

  FIRST_BALL_HOLD = 7,
  NONE = 8
} PowerupTypeEnum;

static const char *s_powerup_names[] = {
  "HOLD",
  "LASER",
  "WIDE",
  "SMALL",
  "LIFE",
  "BOMB",
  "PLASMA",
  "FIRST_BALL_HOLD",
  "NONE"
};

#ifdef PBL_COLOR
  static const uint8_t s_powerup_colors_ARGB8[] = {
    GColorBlueARGB8,
    GColorRedARGB8,
    GColorChromeYellowARGB8,
    GColorWindsorTanARGB8,
    GColorGreenARGB8,
    GColorCyanARGB8,
    GColorFashionMagentaARGB8,
    GColorBlackARGB8,
    GColorBlackARGB8
  };
  #define s_powerup_colors(i)  (GColor8) { .argb = s_powerup_colors_ARGB8[i]}
#endif

#define NUM_ENUM_POWERUPS 7    // number of powerups that can drop from block kills
#define POWERUP_FREQ 1    // a power up will randomly appear a chance of 1/POWERUP_FREQ

static PowerupTypeEnum s_active_powerup;
static bool s_is_holding_ball;

static int16_t max(int16_t a, int16_t b) {
  if (a > b) {
    return a;
  }
  return b;
}

static int16_t min(int16_t a, int16_t b) {
  if (a < b) {
    return a;
  }
  return b;
}

static GPoint get_ball_dir_point() {
  GPoint ball_dir;
  ball_dir.x = (0x00ff * cos_lookup(s_ball_dir_angle)) / TRIG_MAX_RATIO;
  ball_dir.y = (0x00ff * sin_lookup(s_ball_dir_angle)) / TRIG_MAX_RATIO;
  return ball_dir;
}

static int16_t reflect_angle_X(int16_t angle) {
  angle *= -1;
  return angle;
}

static int16_t reflect_angle_Y(int16_t angle) {
  angle = (angle - TRIG_MAX_ANGLE/2)* -1;
  return angle;
}

static void block_layer_draw(Layer *layer, GContext *ctx) {
  uint8_t *block_data = (uint8_t *) layer_get_data(layer);
  GRect bounds = layer_get_bounds(layer);
  // GRect inner_rect


  if (*block_data > 0) {
    graphics_context_set_fill_color(ctx, GColorBlack);
    graphics_fill_rect(ctx, bounds, 0, GCornersAll);
    graphics_context_set_fill_color(ctx, GColorWhite);
    bounds.origin.x += 1;
    bounds.origin.y += 1;
    bounds.size.w -= 2;
    bounds.size.h -= 2;
    graphics_fill_rect(ctx, bounds, 0, GCornersAll);
    graphics_context_set_fill_color(ctx, GColorBlack);
    bounds.origin.x += 1;
    bounds.origin.y += 1;
    bounds.size.w -= 2;
    bounds.size.h -= 2;
    graphics_fill_rect(ctx, bounds, 0, GCornersAll);
  } else {
    layer_set_hidden(layer, true);
  }
}

static void ball_layer_draw(Layer *layer, GContext *ctx) {
  GRect bounds = layer_get_bounds(layer);

  graphics_context_set_fill_color(ctx, GColorBlack);
  const int16_t half_h = bounds.size.h / 2;
  graphics_fill_circle(ctx, GPoint(half_h, half_h), half_h);
}

static void aim_layer_draw(Layer *layer, GContext *ctx) {
  GRect bounds = layer_get_bounds(layer);
  int16_t *aim_angle = (int16_t *) layer_get_data(layer);

  GPoint p0 = GPoint(15, 15);
  GPoint p1 = GPoint(15 + 15 * cos_lookup(*aim_angle) / TRIG_MAX_RATIO,
                     15 + 15 * sin_lookup(*aim_angle) / TRIG_MAX_RATIO);

  graphics_context_set_fill_color(ctx, GColorBlack);
  graphics_draw_line(ctx, p0, p1);
}

static void paddle_layer_draw(Layer *layer, GContext *ctx) {
  GRect bounds = layer_get_bounds(layer);

  #ifdef PBL_COLOR
    GColor8 paddle_color = s_powerup_colors((uint8_t)s_active_powerup);
  #else
    GColor paddle_color = GColorBlack;
  #endif

  graphics_context_set_fill_color(ctx, paddle_color);
  graphics_fill_rect(ctx, bounds, bounds.size.h/2, GCornersAll);
}

static void powerup_layer_draw(Layer *layer, GContext *ctx) {
  uint8_t *layer_data = layer_get_data(layer);
  GRect bounds = layer_get_bounds(layer);

  #ifdef PBL_COLOR
    GColor8 powerup_color = s_powerup_colors(*layer_data);
  #else
    GColor powerup_color = GColorBlack;
  #endif

  graphics_context_set_fill_color(ctx, powerup_color);
  graphics_context_set_text_color(ctx, powerup_color);

  graphics_draw_text(ctx, s_powerup_names[*layer_data], s_arcade_font_8,
    s_powerup_text_frame, GTextOverflowModeWordWrap, GTextAlignmentCenter, NULL);

  graphics_fill_rect(ctx, s_powerup_pill_frame, s_powerup_pill_frame.size.h/2, GCornersAll);
}

static void status_layer_draw(Layer *layer, GContext *ctx) {
  GRect bounds = layer_get_bounds(layer);
  GRect text_bounds = bounds;
  text_bounds.origin.x += 1;
  text_bounds.origin.y += 4;
  text_bounds.size.w -= 2;
  text_bounds.size.h = 8;

  graphics_context_set_fill_color(ctx, GColorBlack);
  graphics_context_set_text_color(ctx, GColorWhite);

  graphics_fill_rect(ctx, bounds, 0, GCornersAll);

  uint8_t buffer_len = 15;
  char buffer[buffer_len];
  snprintf(buffer, buffer_len, "yx%d", s_num_lives);
  buffer[0] = '"';
  graphics_draw_text(ctx, buffer, s_arcade_font_8,
    text_bounds, GTextOverflowModeWordWrap, GTextAlignmentLeft, NULL);

  snprintf(buffer, buffer_len, "LVL%d", s_level + 1);
  graphics_draw_text(ctx, buffer, s_arcade_font_8,
    text_bounds, GTextOverflowModeWordWrap, GTextAlignmentCenter, NULL);

  char *buff_start = buffer + SCORE_MAX_WIDTH;
  uint8_t num_chars = snprintf(buff_start, buffer_len - SCORE_MAX_WIDTH, "%lu", (uint32_t)s_score);
  while (num_chars < SCORE_MAX_WIDTH) {
    buff_start--;
    buff_start[0] = '0';
    num_chars++;
  }
  graphics_draw_text(ctx, buff_start, s_arcade_font_8,
    text_bounds, GTextOverflowModeWordWrap, GTextAlignmentRight, NULL);
}

static void laser_fire_layer_draw(Layer *layer, GContext *ctx) {
  GRect bounds = layer_get_bounds(layer);

  #ifdef PBL_COLOR
    GColor8 fire_color = GColorRed;
  #else
    GColor fire_color = GColorBlack;
  #endif

  graphics_context_set_fill_color(ctx, fire_color);
  graphics_fill_rect(ctx, bounds, bounds.size.h, GCornersAll);
}

static void block_array_destroy() {
  for (int i = 0; i < s_num_blocks; i++) {
    layer_destroy(s_block_layer_array[i]);
  }
  free(s_block_layer_array);
  s_block_layer_array = NULL;
  s_num_blocks = 0;
}

static void powerup_array_destroy() {
  for (int i = 0; i < s_num_powerup_drops; i++) {
    layer_destroy(s_powerup_layer_array[i]);
    if (s_powerup_animation_array[i] != NULL) {
      property_animation_destroy((PropertyAnimation *)s_powerup_animation_array[i]);
    }
  }
  s_num_powerup_drops = 0;
}

static void powerup_array_clear() {
  for (int i = 0; i < MAX_NUM_POWERUP_DROPS; i++) {
    layer_set_hidden(s_powerup_layer_array[i], true);
    if (s_powerup_animation_array[i] != NULL) {
      animation_unschedule((Animation *)s_powerup_animation_array[i]);
    }
  }
  s_num_powerup_drops = 0;
}

static bool powerup_layer_clear(Layer *powerup_layer) {
  bool found_layer = false;
  layer_set_hidden(powerup_layer, true);
  uint8_t *layer_data = layer_get_data(powerup_layer);
  *layer_data = (uint8_t)NONE;
  for (int i = 0; i < s_num_powerup_drops; i++) {
    if (found_layer) {
      s_powerup_layer_array[i-1] = s_powerup_layer_array[i];
      s_powerup_animation_array[i-1] = s_powerup_animation_array[i];
    } else if (powerup_layer == s_powerup_layer_array[i]) {
      found_layer = true;
    }
  }
  if (found_layer) {
    s_num_powerup_drops--;
    s_powerup_layer_array[s_num_powerup_drops] = powerup_layer;
  }
  return found_layer;
}

static void powerup_layers_create() {
  Layer *powerup_layer;
  uint8_t *layer_data;
  GRect frame = (GRect) {
    .origin = {0, 0},
    .size = s_powerup_frame.size
  };
  for (int i = 0; i < MAX_NUM_POWERUP_DROPS; i++) {
    powerup_layer = layer_create_with_data(frame, 1);
    layer_data = layer_get_data(powerup_layer);
    *layer_data = (uint8_t)NONE;
    s_powerup_layer_array[i] = powerup_layer;
    layer_set_update_proc(powerup_layer, powerup_layer_draw);
    layer_add_child(s_main_layer, powerup_layer);
    layer_set_hidden(powerup_layer, true);
  }
  s_num_powerup_drops = 0;
}

static void laser_fire_array_destroy() {
  for (int i = 0; i < s_num_laser_fire; i++) {
    layer_destroy(s_laser_fire_layer_array[i]);
    if (s_laser_fire_animation_array[i] != NULL) {
      property_animation_destroy((PropertyAnimation *)s_laser_fire_animation_array[i]);
    }
  }
  s_num_laser_fire = 0;
}

static void laser_fire_array_clear() {
  for (int i = 0; i < MAX_NUM_LASER_FIRE; i++) {
    layer_set_hidden(s_laser_fire_layer_array[i], true);
    if (s_laser_fire_animation_array[i] != NULL) {
      animation_unschedule((Animation *)s_laser_fire_animation_array[i]);
    }
  }
  s_num_laser_fire = 0;
}

static bool laser_fire_layer_clear(Layer *laser_fire_layer) {
  bool found_layer = false;
  layer_set_hidden(laser_fire_layer, true);
  for (int i = 0; i < s_num_laser_fire; i++) {
    if (found_layer) {
      s_laser_fire_layer_array[i-1] = s_laser_fire_layer_array[i];
      s_laser_fire_animation_array[i-1] = s_laser_fire_animation_array[i];
    } else if (laser_fire_layer == s_laser_fire_layer_array[i]) {
      found_layer = true;
    }
  }
  if (found_layer) {
    s_num_laser_fire--;
    s_laser_fire_layer_array[s_num_laser_fire] = laser_fire_layer;
  }
  return found_layer;
}

static void laser_fire_layers_create() {
  Layer *laser_layer;
  GRect frame = s_laser_fire_frame;
  for (int i = 0; i < MAX_NUM_LASER_FIRE; i++) {
    laser_layer = layer_create(frame);
    s_laser_fire_layer_array[i] = laser_layer;
    layer_set_update_proc(laser_layer, laser_fire_layer_draw);
    layer_add_child(s_main_layer, laser_layer);
    layer_set_hidden(laser_layer, true);
  }
  s_num_laser_fire = 0;
}

static void shoot_laser();
static void reset_paddle();

static void set_active_powerup(PowerupTypeEnum powerup_type) {
  if (powerup_type == LIFE) {
    s_num_lives++;
    layer_mark_dirty(s_status_layer);
  } else if (powerup_type == FIRST_BALL_HOLD) {
    s_is_holding_ball = true;
  }

  s_active_powerup = powerup_type;
  GRect paddle_frame = layer_get_frame(s_paddle_layer);
  uint8_t new_size = PADDLE_WIDTH_STANDARD;
  if (s_active_powerup == WIDE) {
    new_size = PADDLE_WIDTH_WIDE;
  } else if (s_active_powerup == SMALL) {
    new_size = PADDLE_WIDTH_SMALL;
  }
  if (new_size != paddle_frame.size.w) {
    paddle_frame.origin.x += (paddle_frame.size.w - new_size) / 2;
    paddle_frame.size.w = new_size;
    layer_set_frame(s_paddle_layer, paddle_frame);
    layer_mark_dirty(s_paddle_layer);
  }
}

static void ball_animation(uint16_t delay);

static void move_paddle(ClickRecognizerRef recognizer) {
  int16_t numClicks = click_number_of_clicks_counted(recognizer);
  ButtonId buttonId = click_recognizer_get_button_id(recognizer);
  int16_t dirSign = 1;
  if (buttonId == BUTTON_ID_UP) {
    dirSign = -1;
  } else if (buttonId == BUTTON_ID_DOWN) {
    dirSign = 1;
  }

  s_paddle_velocity = PADDLE_MAX_SPEED;
  if (numClicks <= 2) {
    s_paddle_velocity = PADDLE_MAX_SPEED/2;
  }

  s_paddle_velocity *= dirSign;
  GRect frame = layer_get_frame(s_paddle_layer);
  GRect main_frame = layer_get_frame(s_main_layer);

  int16_t new_x = frame.origin.x + s_paddle_velocity;
  if (new_x < 0) {
    new_x = 0;
  } else if (new_x + frame.size.w > main_frame.size.w) {
    new_x = main_frame.size.w - frame.size.w;
  }
  frame.origin.x = new_x;
  layer_set_frame(s_paddle_layer, frame);
  layer_mark_dirty(s_paddle_layer);
}

static void move_aim(ClickRecognizerRef recognizer) {
  int16_t numClicks = click_number_of_clicks_counted(recognizer);
  ButtonId buttonId = click_recognizer_get_button_id(recognizer);
  int16_t dirSign = 1;
  if (buttonId == BUTTON_ID_UP) {
    dirSign = -1;
  } else if (buttonId == BUTTON_ID_DOWN) {
    dirSign = 1;
  }

  int16_t aim_inc = 0;
  if (numClicks % 4 == 1) {
    aim_inc = HOLD_AIM_INC;
  }

  aim_inc *= dirSign;
  int16_t *aim_angle = (int16_t *) layer_get_data(s_aim_layer);
  int16_t new_angle = *aim_angle + aim_inc;
  if (new_angle < -TRIG_MAX_ANGLE*1/8 && new_angle > -TRIG_MAX_ANGLE*3/8) {
    *aim_angle = new_angle;
  }
  layer_mark_dirty(s_paddle_layer);
}

static void reset_paddle() {
  set_active_powerup(FIRST_BALL_HOLD);
  animation_unschedule((Animation *) s_ball_animation);

  GRect main_frame = layer_get_frame(s_main_layer);
  uint8_t paddle_origin_x = main_frame.size.w/2 - PADDLE_WIDTH_STANDARD/2;

  layer_set_frame(s_paddle_layer, (GRect) {
    .origin = {paddle_origin_x, PADDLE_ORIGIN_Y},
    .size = {PADDLE_WIDTH_STANDARD, 5}
  });

  layer_set_frame(s_ball_layer, (GRect) {
    .origin = {paddle_origin_x + 13, PADDLE_ORIGIN_Y-5},
    .size = {5, 5}
  });

  layer_set_frame(s_aim_layer, (GRect) {
    .origin = {paddle_origin_x, PADDLE_ORIGIN_Y-17},
    .size = {PADDLE_WIDTH_STANDARD, 15}
  });

  int16_t *aim_angle = layer_get_data(s_aim_layer);
  *aim_angle = -TRIG_MAX_ANGLE/4;
  layer_set_hidden(s_aim_layer, false);
  powerup_array_clear();
  laser_fire_array_clear();
}

static void btn_dir_rep_click_handler(ClickRecognizerRef recognizer, void *context) {
  if ((s_active_powerup == HOLD || s_active_powerup == FIRST_BALL_HOLD) && s_is_holding_ball) {
    move_aim(recognizer);
  } else {
    move_paddle(recognizer);
  }
}

static void select_rep_click_handler(ClickRecognizerRef recognizer, void *context) {
  if ((s_active_powerup == HOLD || s_active_powerup == FIRST_BALL_HOLD) && s_is_holding_ball) {
    layer_set_hidden(s_aim_layer, true);
    int16_t *aim_angle = layer_get_data(s_aim_layer);
    s_ball_dir_angle = *aim_angle;
    s_is_holding_ball = false;
    ball_animation(0);
    if (s_active_powerup == FIRST_BALL_HOLD) {
      set_active_powerup(NONE);
    }
  } else if (s_active_powerup == LASER) {
    shoot_laser();
  }
}

static void click_config_provider(void *context) {
  window_single_repeating_click_subscribe(BUTTON_ID_SELECT, 150, select_rep_click_handler);
  window_single_repeating_click_subscribe(BUTTON_ID_UP, 30, btn_dir_rep_click_handler);
  window_single_repeating_click_subscribe(BUTTON_ID_DOWN, 30, btn_dir_rep_click_handler);
}

static void hit_block(Layer *block_layer, PowerupTypeEnum hit_by_powerup);
static void scehdule_laser_animation(Layer *laser_fire_layer);
static void load_map_from_resource(uint8_t level_id);

static void laser_fire_find_end(Layer *laser_fire_layer, GRect *finish, Layer **block_layer, bool *hit) {
  GRect laser_fire_frame = layer_get_frame(laser_fire_layer);
  *finish = laser_fire_frame;
  GRect block_frame;
  uint8_t *block_data;
  for (int i = 0; i < 200; i++) {
    finish->origin.y--;
    if (finish->origin.y <= 0) {
      return;
    }
    for (int j = 0; j < s_num_blocks; j++) {
      block_frame = layer_get_frame(s_block_layer_array[j]);
      block_data = layer_get_data(s_block_layer_array[j]);
      if (*block_data > 0 &&
          finish->origin.y < block_frame.origin.y + block_frame.size.h &&
          finish->origin.x < block_frame.origin.x + block_frame.size.w &&
          finish->origin.x + finish->size.w > block_frame.origin.x) {
        if (*hit) {
          *block_layer = s_block_layer_array[j];
        }
        return;
      }
    }
    if (*hit) {
      *hit = false;
      return;
    }
  }
}

static void laser_fire_anim_stopped_handler(Animation *animation, bool finished, void *context) {
  property_animation_destroy((PropertyAnimation *)animation);

  if (context != NULL && finished) {
    Layer *laser_fire_layer = (Layer *)context;
    GRect laser_fire_frame = layer_get_frame(laser_fire_layer);
    GRect finish = laser_fire_frame;
    Layer *block_layer = NULL;
    bool hit = true;
    laser_fire_find_end(laser_fire_layer, &finish, &block_layer, &hit);


    if (hit) {
      if (block_layer != NULL) {
        hit_block(block_layer, LASER);
      }
      laser_fire_layer_clear(laser_fire_layer);
    } else {
      scehdule_laser_animation(laser_fire_layer);
    }
  }
}

static void scehdule_laser_animation(Layer *laser_fire_layer) {
  GRect laser_fire_frame = layer_get_frame(laser_fire_layer);
  GRect finish = laser_fire_frame;
  Layer *block_layer;
  bool hit = false;
  laser_fire_find_end(laser_fire_layer, &finish, &block_layer, &hit);

  int8_t laser_fire_index = -1;
  for (int i = 0; i <= s_num_laser_fire; i++) {
    if (laser_fire_layer == s_laser_fire_layer_array[i]) {
      laser_fire_index = i;
      break;
    }
  }
  if (laser_fire_index == -1) {
    return;
  }

  uint16_t anim_duration = LASER_FIRE_TIME_PER_DIST * (laser_fire_frame.origin.y - finish.origin.y);
  PropertyAnimation *laser_animation = property_animation_create_layer_frame(laser_fire_layer, &laser_fire_frame, &finish);
  s_laser_fire_animation_array[laser_fire_index] = laser_animation;
  animation_set_duration((Animation*)laser_animation, anim_duration);
  animation_set_delay((Animation*)laser_animation, 0);
  animation_set_curve((Animation*)laser_animation, AnimationCurveLinear);
  animation_set_handlers((Animation*)laser_animation, (AnimationHandlers) {
    .stopped = laser_fire_anim_stopped_handler
  }, laser_fire_layer);
  animation_schedule((Animation*)laser_animation);
}

static void shoot_laser() {
  // text_layer_set_text(s_text_layer, "drop powerup");
  GRect paddle_frame = layer_get_frame(s_paddle_layer);
  GRect frame = (GRect) {
    .origin = {
      s_laser_fire_frame.origin.x + paddle_frame.origin.x + paddle_frame.size.w/2,
      s_laser_fire_frame.origin.y + paddle_frame.origin.y
    },
    .size = s_laser_fire_frame.size
  };

  Layer *laser_fire_layer = s_laser_fire_layer_array[s_num_laser_fire];

  layer_set_frame(laser_fire_layer, frame);
  layer_set_hidden(laser_fire_layer, false);
  layer_mark_dirty(laser_fire_layer);

  scehdule_laser_animation(laser_fire_layer);

  s_num_laser_fire++;
}

static void powerup_anim_stopped_handler(Animation *animation, bool finished, void *context) {
  property_animation_destroy((PropertyAnimation *)animation);

  if (context != NULL && finished) {
    Layer *powerup_layer = (Layer *)context;
    uint8_t *powerup_data = layer_get_data(powerup_layer);
    GRect powerup_frame = layer_get_frame(powerup_layer);
    GRect paddle_frame = layer_get_frame(s_paddle_layer);

    GRect pill_frame = s_powerup_pill_frame;
    pill_frame.origin.x += powerup_frame.origin.x;
    pill_frame.origin.y += powerup_frame.origin.y;

    if (pill_frame.origin.x < paddle_frame.origin.x + paddle_frame.size.w &&
        pill_frame.origin.x + pill_frame.size.w > paddle_frame.origin.x) {
      set_active_powerup((PowerupTypeEnum)(*powerup_data));
      s_score += SCORE_POWERUP_CATCH;
    }

    powerup_layer_clear(powerup_layer);
  }
}

static void drop_powerup(PowerupTypeEnum powerup, Layer *block_layer) {
  // text_layer_set_text(s_text_layer, "drop powerup");
  GRect frame = layer_get_frame(block_layer);

  frame.origin.x += s_powerup_frame.origin.x;
  frame.origin.y += s_powerup_frame.origin.y;
  frame.size = s_powerup_frame.size;

  Layer *powerup_layer = s_powerup_layer_array[s_num_powerup_drops];
  uint8_t *layer_data = layer_get_data(powerup_layer);
  *layer_data = (uint8_t)powerup;
  APP_LOG(APP_LOG_LEVEL_DEBUG, "powerup drop int %d", *layer_data);

  layer_set_frame(powerup_layer, frame);
  layer_set_hidden(powerup_layer, false);
  layer_mark_dirty(powerup_layer);

  // Schedule the next animation
  GRect finish = frame;
  GRect paddle_frame = layer_get_frame(s_paddle_layer);
  finish.origin.y = paddle_frame.origin.y - frame.size.h;
  uint16_t anim_duration = POWERUP_TIME_PER_DIST * (finish.origin.y - frame.origin.y);
  PropertyAnimation *powerup_animation = property_animation_create_layer_frame(powerup_layer, &frame, &finish);
  s_powerup_animation_array[s_num_powerup_drops] = powerup_animation;
  animation_set_duration((Animation*)powerup_animation, anim_duration);
  animation_set_delay((Animation*)powerup_animation, 0);
  animation_set_curve((Animation*)powerup_animation, AnimationCurveLinear);
  animation_set_handlers((Animation*)powerup_animation, (AnimationHandlers) {
    .stopped = powerup_anim_stopped_handler
  }, powerup_layer);
  animation_schedule((Animation*)powerup_animation);

  s_num_powerup_drops++;
}

static bool check_finished_level() {
  uint8_t *block_data;
  bool finished_level = true;
  for (int i = 0; i < s_num_blocks; i++) {
    block_data = layer_get_data(s_block_layer_array[i]);
    if (*block_data != 0 && *block_data != 0xff) {
      finished_level = false;
    }
  }

  if (finished_level) {
    s_level++;
    s_score += SCORE_LEVEL_COMPLETE;
    layer_mark_dirty(s_status_layer);
    load_map_from_resource(s_level);
    reset_paddle();
  }
  return finished_level;
}

static void hit_block(Layer *block_layer, PowerupTypeEnum hit_by_powerup) {
  uint8_t *block_data = layer_get_data(block_layer);
  if (*block_data == 0xff) {
    // solid block
  } else if (*block_data == 0) {
    // destroyed block
  } else {
    (*block_data)--;
    if (hit_by_powerup == PLASMA) {
      *block_data = 0;
    }
    layer_mark_dirty(block_layer);

    if (*block_data == 0) {
      s_score += SCORE_BLOCK_KILL;
      // layer_mark_dirty(s_status_layer);
    }


    uint16_t random_number = rand() % (NUM_ENUM_POWERUPS*POWERUP_FREQ);
    if (random_number < NUM_ENUM_POWERUPS && s_num_powerup_drops < MAX_NUM_POWERUP_DROPS) {
      PowerupTypeEnum powerup = (PowerupTypeEnum)random_number;
      drop_powerup(powerup, block_layer);
    }

    if (s_active_powerup == BOMB && hit_by_powerup != BOMB) {
      GRect block_frame;
      GPoint block_centre;
      GRect ball_frame = layer_get_frame(s_ball_layer);
      GRect blast_frame = (GRect) {
        .origin = {
          ball_frame.origin.x - BOMB_BLAST_RADIUS,
          ball_frame.origin.y - BOMB_BLAST_RADIUS
        },
        .size = {
          BOMB_BLAST_RADIUS*2,
          BOMB_BLAST_RADIUS*2
        }
      };
      for (int i = 0; i < s_num_blocks; i++) {
        block_frame = layer_get_frame(s_block_layer_array[i]);
        block_centre = grect_center_point(&block_frame);
        if (grect_contains_point(&blast_frame, &block_centre)) {
          hit_block(s_block_layer_array[i], BOMB);
        }
      }
    }
    
    if (hit_by_powerup == LASER) {
      check_finished_level();
    }
  }
}

static BallReflectionTypeEnum ball_reflection(GRect *ball_rect, int16_t *new_ball_dir_angle, bool *hit) {
  int i;
  GPoint ball_dir = get_ball_dir_point();
  int16_t ball_dir_abs_x = abs(ball_dir.x);
  int16_t ball_dir_abs_y = abs(ball_dir.y);
  GRect arena_bounds = layer_get_bounds(s_main_layer);
  GRect paddle_frame = layer_get_frame(s_paddle_layer);
  GRect init_rect = *ball_rect;
  GRect next_rect = init_rect;
  *new_ball_dir_angle = s_ball_dir_angle;


  for (i = 0; i < 200; i++) {
    if (i == 0) {
      next_rect.origin.x += ball_dir.x / ball_dir_abs_x;
      next_rect.origin.y += ball_dir.y / ball_dir_abs_y;
    } else if (ball_dir_abs_x > ball_dir_abs_y) {
      next_rect.origin.x += ball_dir.x / ball_dir_abs_x;
      next_rect.origin.y += (i*ball_dir.y / ball_dir_abs_x) - ((i-1)*ball_dir.y / ball_dir_abs_x);
    } else {
      next_rect.origin.x += (i*ball_dir.x / ball_dir_abs_y) - ((i-1)*ball_dir.x / ball_dir_abs_y);
      next_rect.origin.y += ball_dir.y / ball_dir_abs_y;
    }

    // APP_LOG(APP_LOG_LEVEL_DEBUG, "ball orig y:%d, next orig y:%d, paddle orig y:%d",
    //   ball_rect->origin.y, next_rect.origin.y, paddle_frame.origin.y);


    if (next_rect.origin.x < 0 ||
        next_rect.origin.x + next_rect.size.w > arena_bounds.size.w) {
      if (*hit) {
        *new_ball_dir_angle = reflect_angle_Y(*new_ball_dir_angle);
      }
      return WALL_VERT;
    } else if (next_rect.origin.y < 0) {
      if (*hit) {
        *new_ball_dir_angle = reflect_angle_X(*new_ball_dir_angle);
      }
      return WALL_HORZ;
    } else if (init_rect.origin.y + init_rect.size.h > arena_bounds.size.h) {
      return DEATH;
    } else if (next_rect.origin.y + next_rect.size.h > arena_bounds.size.h) {
      *ball_rect = next_rect;
      return IMMINENT_DEATH;
    } else if (next_rect.origin.y < paddle_frame.origin.y &&
               next_rect.origin.y + next_rect.size.h > paddle_frame.origin.y &&
               next_rect.origin.x < paddle_frame.origin.x + paddle_frame.size.w &&
               next_rect.origin.x + next_rect.size.w > paddle_frame.origin.x &&
               !(ball_rect->origin.y < paddle_frame.origin.y + paddle_frame.size.w &&
                 ball_rect->origin.y + ball_rect->size.h > paddle_frame.origin.y &&
                 ball_rect->origin.x < paddle_frame.origin.x + paddle_frame.size.w &&
                 ball_rect->origin.x + ball_rect->size.w > paddle_frame.origin.x)) {
      // hit the actual paddle
      // *ball_rect = next_rect;
      if (*hit) {
        *new_ball_dir_angle = reflect_angle_X(*new_ball_dir_angle);
        int16_t dist_from_centre = (next_rect.origin.x + next_rect.size.w/2) -
                                   (paddle_frame.origin.x + paddle_frame.size.w/2);
        *new_ball_dir_angle = -TRIG_MAX_ANGLE/4 +
                              (TRIG_MAX_ANGLE/8 * dist_from_centre*2) / paddle_frame.size.w;
      }
      return PADDLE_HIT;
    } else if (next_rect.origin.y + next_rect.size.h >= paddle_frame.origin.y &&
               ball_rect->origin.y + ball_rect->size.h < paddle_frame.origin.y) {
      // hit the line where the paddle should be
      *ball_rect = next_rect;
      return PADDLE_PHANTOM;
    } else {
      // check blocks
      GRect block_frame;
      bool is_block_alive;
      uint8_t *block_data;
      for (int j = 0; j < s_num_blocks; j++) {
        block_data = (uint8_t *)layer_get_data(s_block_layer_array[j]);
        is_block_alive = (*block_data) > 0;
        if (is_block_alive) {
          block_frame = layer_get_frame(s_block_layer_array[j]);
          if ((next_rect.origin.y +1 == block_frame.origin.y + block_frame.size.h ||
               next_rect.origin.y + next_rect.size.h -1 == block_frame.origin.y) &&
              next_rect.origin.x < block_frame.origin.x + block_frame.size.w &&
              next_rect.origin.x + next_rect.size.w > block_frame.origin.x) {
            if (*hit) {
              if (s_active_powerup != PLASMA) {
                *new_ball_dir_angle = reflect_angle_X(*new_ball_dir_angle);
              }
              hit_block(s_block_layer_array[j], NONE);
            }
            return BLOCK_HORZ;
          } else if (next_rect.origin.y < block_frame.origin.y + block_frame.size.h &&
                     next_rect.origin.y + next_rect.size.h > block_frame.origin.y &&
                     (next_rect.origin.x +1 == block_frame.origin.x + block_frame.size.w ||
                     next_rect.origin.x + next_rect.size.w -1 == block_frame.origin.x)) {
            if (*hit) {
              if (s_active_powerup != PLASMA) {
                *new_ball_dir_angle = reflect_angle_Y(*new_ball_dir_angle);
              }
              hit_block(s_block_layer_array[j], NONE);
            }
            return BLOCK_VERT;
          }
        }
      }
    }

    *ball_rect = next_rect;
    *hit = false;
  }
  return NO_REFLECT;
}

static void ball_anim_stopped_handler(Animation *animation, bool finished, void *context) {
  property_animation_destroy(s_ball_animation);

  if (!finished || s_active_powerup == FIRST_BALL_HOLD) {
    // dont restart the animation
    psleep(100);
  } else {
    int16_t new_ball_dir_angle;
    GRect ball_rect_changing = layer_get_frame(s_ball_layer);
    bool hit = true;
    BallReflectionTypeEnum reflect_type = ball_reflection(&ball_rect_changing, &new_ball_dir_angle, &hit);
    if (reflect_type == DEATH) {
      text_layer_set_text(s_text_layer, "DEATH");
      s_num_lives--;
      if (s_num_lives > 0) {
        reset_paddle();
      } else {
        window_stack_pop(true);
      }
    } else if (reflect_type == PADDLE_HIT && s_active_powerup == HOLD) {
      GRect aim_rect = layer_get_frame(s_aim_layer);
      GRect ball_rect = layer_get_frame(s_ball_layer);
      aim_rect.origin.x = ball_rect.origin.x - 13;
      layer_set_frame(s_aim_layer, aim_rect);
      layer_set_hidden(s_aim_layer, false);
      s_is_holding_ball = true;
    } else {
      bool finished_level = false;
      if (hit) {
        finished_level = check_finished_level();
        s_ball_dir_angle = new_ball_dir_angle;
      }
      if (!finished_level) {
        ball_animation(0);
      }
    }
  }
}

static void ball_animation(uint16_t delay) {
  // Determine start and finish positions
  GRect start, finish;
  int16_t new_ball_dir_angle;

  start = layer_get_frame(s_ball_layer);
  finish = start;

  int i;
  bool hit = false;
  BallReflectionTypeEnum reflect_type = ball_reflection(&finish, &new_ball_dir_angle, &hit);

  int16_t rough_dist = abs(finish.origin.x - start.origin.x) +
                       abs(finish.origin.y - start.origin.y);

  // Schedule the next animation
  s_ball_animation = property_animation_create_layer_frame(s_ball_layer, &start, &finish);
  animation_set_duration((Animation*)s_ball_animation, BALL_TIME_PER_DIST*rough_dist);
  animation_set_delay((Animation*)s_ball_animation, delay);
  animation_set_curve((Animation*)s_ball_animation, AnimationCurveLinear);
  animation_set_handlers((Animation*)s_ball_animation, (AnimationHandlers) {
    .stopped = ball_anim_stopped_handler
  }, NULL);
  animation_schedule((Animation*)s_ball_animation);
}

static void load_map_from_buffer(uint8_t *buffer, uint8_t buffer_len) {
  s_num_blocks = buffer_len / 3;

  s_block_layer_array = (Layer **)malloc(s_num_blocks*(sizeof(Layer *)));

  GRect block_rect = (GRect) { .origin = {0, 0}, .size = {16, 8}};

  // create blocks
  int16_t i;
  for (i = 0; i < s_num_blocks; i++) {
    block_rect.origin.x = buffer[i*3 + 1];
    block_rect.origin.y = buffer[i*3 + 2];
    Layer *new_block_layer = layer_create_with_data(block_rect, 1);
    uint8_t *layer_data = (uint8_t *)layer_get_data(new_block_layer);
    *layer_data = buffer[i*3];
    layer_set_update_proc(new_block_layer, block_layer_draw);
    layer_add_child(s_main_layer, new_block_layer);
    s_block_layer_array[i] = new_block_layer;
  }
}

static void load_map_from_resource(uint8_t level_id) {
  block_array_destroy();

  // Get resource and size
  ResHandle handle = resource_get_handle(s_map_resource_array[level_id]);
  uint8_t res_size = (uint8_t)resource_size(handle);
  uint8_t *buffer = (uint8_t*)malloc(res_size);
  resource_load(handle, buffer, res_size);

  load_map_from_buffer(buffer, res_size);
  free(buffer);
}

static bool load_resume_data_from_persist() {
  if (persist_exists(P_BLOCKS_DATA_KEY)) {
    block_array_destroy();

    uint8_t res_size = persist_get_size(P_BLOCKS_DATA_KEY);

    uint8_t *buffer = (uint8_t*)malloc(res_size);
    s_num_blocks = persist_read_data(P_BLOCKS_DATA_KEY, buffer, res_size) / 3;

    load_map_from_buffer(buffer, res_size);

    free(buffer);

    if (persist_exists(P_BALL_DATA_KEY)) {
      int16_t ball_buff[3];
      persist_read_data(P_BALL_DATA_KEY, ball_buff, 6);
      GRect frame = layer_get_frame(s_ball_layer);
      frame.origin.x = ball_buff[0];
      frame.origin.y = ball_buff[1];
      s_ball_dir_angle = ball_buff[2];
      layer_set_frame(s_ball_layer, frame);
    }

    if (persist_exists(P_PADDLE_KEY)) {
      GRect frame = layer_get_frame(s_paddle_layer);
      frame.origin.x = persist_read_int(P_PADDLE_KEY);
      layer_set_frame(s_paddle_layer, frame);
    }

    if (persist_exists(P_POWERUP_KEY)) {
      set_active_powerup((PowerupTypeEnum) persist_read_int(P_POWERUP_KEY));
      if (s_active_powerup == FIRST_BALL_HOLD) {
        reset_paddle();
      } else {
        layer_set_hidden(s_aim_layer, true);
      }
    }

    if (persist_exists(P_LEVEL_KEY)) {
      s_level = persist_read_int(P_LEVEL_KEY);
    }

    if (persist_exists(P_LIVES_KEY)) {
      s_num_lives = persist_read_int(P_LIVES_KEY);
    }

    if (persist_exists(P_SCORE_KEY)) {
      s_score = persist_read_int(P_SCORE_KEY);
    }

    layer_mark_dirty(s_status_layer);

    if (s_active_powerup != FIRST_BALL_HOLD) {
      ball_animation(1000);
    }

    return true;
  } else {
    return false;
  }
}

static void persist_resume_data() {
  if (s_num_blocks > 0) {
    uint8_t res_size = s_num_blocks*3;
    uint8_t buffer[256];

    for (int i = 0; i < s_num_blocks; i++) {
      uint8_t *layer_data = (uint8_t *)layer_get_data(s_block_layer_array[i]);
      GRect frame = layer_get_frame(s_block_layer_array[i]);
      buffer[i*3] = *layer_data;
      buffer[i*3+1] = frame.origin.x;
      buffer[i*3+2] = frame.origin.y;
    }

    persist_write_data(P_BLOCKS_DATA_KEY, buffer, res_size);

    int16_t ball_buff[3];
    GRect ball_frame = layer_get_frame(s_ball_layer);
    ball_buff[0] = ball_frame.origin.x;
    ball_buff[1] = ball_frame.origin.y;
    ball_buff[2] = s_ball_dir_angle;
    persist_write_data(P_BALL_DATA_KEY, ball_buff, 6);

    GRect paddle_frame = layer_get_frame(s_paddle_layer);
    persist_write_int(P_PADDLE_KEY, paddle_frame.origin.x);

    persist_write_int(P_POWERUP_KEY, s_active_powerup);

    persist_write_int(P_LEVEL_KEY, s_level);
    persist_write_int(P_LIVES_KEY, s_num_lives);
    persist_write_int(P_SCORE_KEY, s_score);
  }
}

static void game_window_load(Window *window) {
  APP_LOG(APP_LOG_LEVEL_DEBUG, "game load");
  Layer *window_layer = window_get_root_layer(window);
  GRect bounds = layer_get_bounds(window_layer);

  s_main_layer = layer_create((GRect) {
    .origin = {0, STATUS_LAYER_HEIGHT},
    .size = {bounds.size.w, bounds.size.h - STATUS_LAYER_HEIGHT}
  });
  layer_add_child(window_layer, s_main_layer);

  s_status_layer = layer_create((GRect) {
    .origin = {0, 0},
    .size = {bounds.size.w, STATUS_LAYER_HEIGHT}
  });
  layer_set_update_proc(s_status_layer, status_layer_draw);
  layer_add_child(window_layer, s_status_layer);


  s_text_layer = text_layer_create((GRect) {
    .origin = { 0, 10 },
    .size = { bounds.size.w, 20 }
  });
  text_layer_set_font(s_text_layer, s_arcade_font_8);
  text_layer_set_text(s_text_layer, "Press a button");
  text_layer_set_text_alignment(s_text_layer, GTextAlignmentCenter);
  layer_add_child(s_main_layer, text_layer_get_layer(s_text_layer));

  s_ball_layer = layer_create((GRect) {
    .origin = {113, PADDLE_ORIGIN_Y-5},
    .size = {5, 5}
  });
  layer_set_update_proc(s_ball_layer, ball_layer_draw);
  layer_add_child(s_main_layer, s_ball_layer);

  s_paddle_layer = layer_create((GRect) {
    .origin = {100, PADDLE_ORIGIN_Y},
    .size = {PADDLE_WIDTH_STANDARD, 5}
  });
  layer_set_update_proc(s_paddle_layer, paddle_layer_draw);
  layer_add_child(s_main_layer, s_paddle_layer);

  s_aim_layer = layer_create_with_data((GRect) {
    .origin = {100, PADDLE_ORIGIN_Y-17},
    .size = {PADDLE_WIDTH_STANDARD, 15}
  }, 2);
  int16_t *aim_angle = layer_get_data(s_aim_layer);
  *aim_angle = -TRIG_MAX_ANGLE/4;
  layer_set_update_proc(s_aim_layer, aim_layer_draw);
  layer_add_child(s_main_layer, s_aim_layer);

  powerup_layers_create();
  laser_fire_layers_create();

  if (s_is_resume && load_resume_data_from_persist()) {

  } else {
    load_map_from_resource(0);
    set_active_powerup(FIRST_BALL_HOLD);
    reset_paddle();

    s_level = 0;
    s_num_lives = 3;
    s_score = 0;
  }


  char buffer[8];
  clock_copy_time_string(buffer, 8);
  for (int i = 0; i < 8; i++) {
    if (buffer[i] == ':') {
      srand(buffer[i+2]);
      break;
    }
  }
}

static void game_window_unload(Window *window) {
  APP_LOG(APP_LOG_LEVEL_DEBUG, "game unload");

  animation_unschedule_all();

  persist_resume_data();

  layer_destroy((Layer *)s_text_layer);
  layer_destroy(s_ball_layer);
  layer_destroy(s_paddle_layer);
  layer_destroy(s_aim_layer);
  layer_destroy(s_status_layer);

  block_array_destroy();
  powerup_array_destroy();
  laser_fire_array_destroy();
  layer_destroy(s_main_layer);
}

static void menu_new_game_callback(int index, void *context) {
  s_is_resume = false;
  window_stack_push(s_main_window, true);
}

static void menu_resume_callback(int index, void *context) {
  if (persist_exists(P_BLOCKS_DATA_KEY)) {
    s_is_resume = true;
    window_stack_push(s_main_window, true);
  }
}

static void menu_window_load(Window *window) {
  Layer *window_layer = window_get_root_layer(window);
  GRect bounds = layer_get_bounds(window_layer);

  s_menu_items[0].title = "Resume";
  s_menu_items[0].callback = menu_resume_callback;

  s_menu_items[1].title = "New Game";
  s_menu_items[1].callback = menu_new_game_callback;
  s_menu_section.num_items = 2;
  s_menu_section.items = s_menu_items;

  s_menu_layer = simple_menu_layer_create((GRect) {
    .origin = {0, 0},
    .size = bounds.size
  }, window, &s_menu_section, 1, NULL);

  layer_add_child(window_layer, (Layer *)s_menu_layer);
}

static void menu_window_unload(Window *window) {
  simple_menu_layer_destroy(s_menu_layer);
}

static void init(void) {
  s_menu_window = window_create();

  s_main_window = window_create();

  #ifdef PBL_PLATFORM_APLITE
    window_set_fullscreen(s_main_window, true);
  #endif

  s_arcade_font_8 = fonts_load_custom_font(resource_get_handle(RESOURCE_ID_ARCADE_FONT_8));

  window_set_click_config_provider(s_main_window, click_config_provider);
  window_set_window_handlers(s_main_window, (WindowHandlers) {
    .load = game_window_load,
    .unload = game_window_unload,
  });

  window_set_window_handlers(s_menu_window, (WindowHandlers) {
    .load = menu_window_load,
    .unload = menu_window_unload,
  });

  const bool animated = true;
  window_stack_push(s_menu_window, animated);
}

static void deinit(void) {
  // Stop any animation in progress
  animation_unschedule_all();

  block_array_destroy();
  powerup_array_destroy();

  fonts_unload_custom_font(s_arcade_font_8);

  // Destroy main Window
  window_destroy(s_main_window);
  window_destroy(s_menu_window);
}

int main(void) {
  init();

  APP_LOG(APP_LOG_LEVEL_DEBUG, "Done initializing, pushed window: %p", s_main_window);

  app_event_loop();
  deinit();
}

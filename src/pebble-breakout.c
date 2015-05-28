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
         `-dN/+s                    ymNNMMmdddhyhh.                                          
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

#define MAX_NUM_POWERUP_DROPS 10 // maximum number of currently dropping powerups

static Window *s_menu_window;
static SimpleMenuLayer *s_menu_layer;
static SimpleMenuSection s_menu_section;
static SimpleMenuItem s_menu_items[2];
static Window *s_main_window;
static Layer *s_main_layer;
static TextLayer *s_text_layer;
static Layer *s_ball_layer;
static int16_t s_ball_dir_angle;
static PropertyAnimation *s_ball_animation;
static Layer *s_paddle_layer;
static int16_t s_paddle_velocity;
static const int16_t S_PADDLE_MAX_SPEED = 8;
static const int16_t S_HOLD_AIM_INC = TRIG_MAX_ANGLE/0x30;
static const int16_t S_BALL_TIME_PER_DIST = 12;
static Layer **s_block_layer_array;
static uint16_t s_num_blocks = 0;
static Layer *s_aim_layer;
static bool is_resume;
static Layer *s_powerup_layer_array[MAX_NUM_POWERUP_DROPS];
static uint8_t s_num_powerup_drops = 0;
static PropertyAnimation *powerup_animation_array[MAX_NUM_POWERUP_DROPS];

#define s_powerup_frame  (GRect) { .origin = {-7, 0}, .size = {32, 20} }

#define s_powerup_text_frame (GRect) { .origin = {0, 0}, .size = {32, 16} }

#define s_powerup_pill_frame (GRect) { .origin = {13, 17}, .size = {6, 3} }

#define P_PADDLE_KEY 0        // int for x value of origin of paddle layer
#define P_BALL_DATA_KEY 1     // array of 3 int16_t, [x, y, angle]    2 bytes per int16_t * 3 = 6 bytes 
#define P_POWERUP_KEY 2       // PowerupTypeEnum saved as an int
#define P_BLOCKS_DATA_KEY 4   // array of bytes with the same format as the file (HH XX YY) HH is the nubmer of hits remaining

#define PADDLE_WIDTH_STANDARD 30
#define PADDLE_WIDTH_WIDE 60

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
  FIRST_BALL_HOLD = 3,
  NONE = 4
} PowerupTypeEnum;

static const char *s_powerup_names[] =
  {"HOLD", "LASER", "WIDE", "FIRST_BALL_HOLD", "NONE"};

#ifdef PBL_PLATFORM_BASALT
  static const uint8_t s_powerup_colors_ARGB8[] = {GColorBlueARGB8, GColorRedARGB8, GColorGreenARGB8, GColorBlackARGB8, GColorBlackARGB8};
  #define s_powerup_colors(i)  (GColor8) { .argb = s_powerup_colors_ARGB8[i]}
#endif

#define NUM_ENUM_POWERUPS 3    // number of powerups that can drop from block kills
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

static void free_block_array() {
  for (int i = 0; i < s_num_blocks; i++) {
    layer_destroy(s_block_layer_array[i]);
  }
  free(s_block_layer_array);
  s_block_layer_array = NULL;
  s_num_blocks = 0;
}

static void free_powerup_array() {
  for (int i = 0; i < s_num_powerup_drops; i++) {
    layer_destroy(s_powerup_layer_array[i]);
  }
  s_num_powerup_drops = 0;
}

static bool powerup_layer_destroy(Layer *powerup_layer) {
  bool found_layer = false;
  for (int i = 0; i < s_num_powerup_drops; i++) {
    if (found_layer) {
      s_powerup_layer_array[i-1] = s_powerup_layer_array[i];
    } else if (powerup_layer == s_powerup_layer_array[i]) {
      found_layer = true;
      layer_set_hidden(powerup_layer, true);
      layer_destroy(powerup_layer);
    }
  }
  if (found_layer) {
    s_num_powerup_drops--;
    s_powerup_layer_array[s_num_powerup_drops] = NULL;
  }
  return found_layer;
}

static void ball_animation();

static void select_click_handler(ClickRecognizerRef recognizer, void *context) {
  text_layer_set_text(s_text_layer, "Select");

  if ((s_active_powerup == HOLD || s_active_powerup == FIRST_BALL_HOLD) && s_is_holding_ball) {
    layer_set_hidden(s_aim_layer, true);
    int16_t *aim_angle = layer_get_data(s_aim_layer);
    s_ball_dir_angle = *aim_angle;
    s_is_holding_ball = false;
    ball_animation();
  } else if (s_active_powerup == LASER) {
    // TODO: shoot laser
  }
}

static void move_paddle(ClickRecognizerRef recognizer) {
  int16_t numClicks = click_number_of_clicks_counted(recognizer);
  ButtonId buttonId = click_recognizer_get_button_id(recognizer);
  int16_t dirSign = 1;
  if (buttonId == BUTTON_ID_UP) {
    dirSign = -1;
  } else if (buttonId == BUTTON_ID_DOWN) {
    dirSign = 1;
  }

  s_paddle_velocity = S_PADDLE_MAX_SPEED;
  if (numClicks <= 2) {
    s_paddle_velocity = S_PADDLE_MAX_SPEED/2;
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
    aim_inc = S_HOLD_AIM_INC;
  }

  aim_inc *= dirSign;
  int16_t *aim_angle = (int16_t *) layer_get_data(s_aim_layer);
  int16_t new_angle = *aim_angle + aim_inc;
  if (new_angle < -TRIG_MAX_ANGLE*1/8 && new_angle > -TRIG_MAX_ANGLE*3/8) {
    *aim_angle = new_angle;
  }
  layer_mark_dirty(s_paddle_layer);
}

static void btn_rep_handler(ClickRecognizerRef recognizer, void *context) {
  text_layer_set_text(s_text_layer, "Up Press");
  if ((s_active_powerup == HOLD || s_active_powerup == FIRST_BALL_HOLD) && s_is_holding_ball) {
    move_aim(recognizer);
  } else {
    move_paddle(recognizer);
  }
}

static void click_config_provider(void *context) {
  window_single_click_subscribe(BUTTON_ID_SELECT, select_click_handler);
  window_single_repeating_click_subscribe(BUTTON_ID_UP, 30, btn_rep_handler);
  window_single_repeating_click_subscribe(BUTTON_ID_DOWN, 30, btn_rep_handler);
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

  #ifdef PBL_PLATFORM_BASALT
    GColor8 paddle_color = s_powerup_colors(s_active_powerup);
  #else
    GColor paddle_color = GColorBlack;
  #endif

  graphics_context_set_fill_color(ctx, paddle_color);
  graphics_fill_rect(ctx, bounds, bounds.size.h/2, GCornersAll);
}

static void powerup_layer_draw(Layer *layer, GContext *ctx) {
  GRect bounds = layer_get_bounds(layer);

  uint8_t *layer_data = layer_get_data(layer);

  #ifdef PBL_PLATFORM_BASALT
    GColor8 powerup_color = s_powerup_colors(*layer_data);
  #else
    GColor powerup_color = GColorBlack;
  #endif

  graphics_context_set_fill_color(ctx, powerup_color);
  graphics_context_set_text_color(ctx, powerup_color);

  graphics_draw_text(ctx, s_powerup_names[*layer_data], fonts_get_system_font(FONT_KEY_GOTHIC_14),
    s_powerup_text_frame, GTextOverflowModeWordWrap, GTextAlignmentCenter, NULL);

  graphics_fill_rect(ctx, s_powerup_pill_frame, s_powerup_pill_frame.size.h/2, GCornersAll);
}

static void powerup_anim_stopped_handler(Animation *animation, bool finished, void *context) {
  property_animation_destroy((PropertyAnimation *)animation);
  text_layer_set_text(s_text_layer, "powerup hit bottom");

  if (context != NULL) {
    Layer *powerup_layer = (Layer *)context;
    uint8_t *powerup_data = layer_get_data(powerup_layer);
    GRect powerup_frame = layer_get_frame(powerup_layer);
    GRect paddle_frame = layer_get_frame(s_paddle_layer);

    GRect pill_frame = s_powerup_pill_frame;
    pill_frame.origin.x += powerup_frame.origin.x;
    pill_frame.origin.y += powerup_frame.origin.y;

    if (pill_frame.origin.x < paddle_frame.origin.x + paddle_frame.size.w &&
        pill_frame.origin.x + pill_frame.size.w > paddle_frame.origin.x) {
      text_layer_set_text(s_text_layer, "caught a powerup");
      s_active_powerup = (PowerupTypeEnum)(*powerup_data);

      paddle_frame.size.w = PADDLE_WIDTH_STANDARD;
      if (s_active_powerup == WIDE) {
        paddle_frame.size.w = PADDLE_WIDTH_WIDE;
      }
      layer_set_frame(s_paddle_layer, paddle_frame);
      layer_mark_dirty(s_paddle_layer);
    }

    powerup_layer_destroy(powerup_layer);
  }
}

static void drop_powerup(PowerupTypeEnum powerup, Layer *block_layer) {
  // text_layer_set_text(s_text_layer, "drop powerup");
  GRect frame = layer_get_frame(block_layer);

  frame.origin.x += s_powerup_frame.origin.x;
  frame.origin.y += s_powerup_frame.origin.y;
  frame.size = s_powerup_frame.size;

  Layer *powerup_layer = layer_create_with_data(frame, 1); // TODO: this line causes issues on phone but not emulator, out of mem??
  uint8_t *layer_data = layer_get_data(powerup_layer);
  *layer_data = (uint8_t)powerup;
  s_powerup_layer_array[s_num_powerup_drops] = powerup_layer;
  layer_set_update_proc(powerup_layer, powerup_layer_draw);
  layer_add_child(s_main_layer, powerup_layer);


  // Schedule the next animation
  GRect finish = frame;
  GRect paddle_frame = layer_get_frame(s_paddle_layer);
  finish.origin.y = paddle_frame.origin.y - frame.size.h;
  PropertyAnimation *powerup_animation = property_animation_create_layer_frame(powerup_layer, &frame, &finish);
  powerup_animation_array[s_num_powerup_drops] = powerup_animation;
  animation_set_duration((Animation*)powerup_animation, 3000);
  animation_set_delay((Animation*)powerup_animation, 0);
  animation_set_curve((Animation*)powerup_animation, AnimationCurveLinear);
  animation_set_handlers((Animation*)powerup_animation, (AnimationHandlers) {
    .stopped = powerup_anim_stopped_handler
  }, powerup_layer);
  animation_schedule((Animation*)powerup_animation);

  s_num_powerup_drops++;
}

static void hit_block(Layer *block_layer) {
  uint8_t *block_data = layer_get_data(block_layer);
  if (*block_data == 0xff) {
    // solid block
  } else if (*block_data == 0) {
    // destroyed block
  } else {
    (*block_data)--;
    layer_mark_dirty(block_layer);

    // TODO: check if level is finished

    uint16_t random_number = rand() % (NUM_ENUM_POWERUPS*POWERUP_FREQ);
    if (random_number < NUM_ENUM_POWERUPS && s_num_powerup_drops < MAX_NUM_POWERUP_DROPS) {
      PowerupTypeEnum powerup = (PowerupTypeEnum)random_number;
      drop_powerup(powerup, block_layer);
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
              *new_ball_dir_angle = reflect_angle_X(*new_ball_dir_angle);
              hit_block(s_block_layer_array[j]);
            }
            return BLOCK_HORZ;
          } else if (next_rect.origin.y < block_frame.origin.y + block_frame.size.h &&
                     next_rect.origin.y + next_rect.size.h > block_frame.origin.y &&
                     (next_rect.origin.x +1 == block_frame.origin.x + block_frame.size.w ||
                     next_rect.origin.x + next_rect.size.w -1 == block_frame.origin.x)) {
            if (*hit) {
              *new_ball_dir_angle = reflect_angle_Y(*new_ball_dir_angle);
              hit_block(s_block_layer_array[j]);
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

  // Schedule the next one, unless the app is exiting
  if (finished) {
    int16_t new_ball_dir_angle;
    GRect ball_rect_changing = layer_get_frame(s_ball_layer);
    bool hit = true;
    BallReflectionTypeEnum reflect_type = ball_reflection(&ball_rect_changing, &new_ball_dir_angle, &hit);
    if (reflect_type == DEATH) {
      text_layer_set_text(s_text_layer, "DEATH");
      window_stack_pop(true);
    } else if (reflect_type == PADDLE_HIT && s_active_powerup == HOLD) {
      GRect aim_rect = layer_get_frame(s_aim_layer);
      GRect ball_rect = layer_get_frame(s_ball_layer);
      aim_rect.origin.x = ball_rect.origin.x - 13;
      layer_set_frame(s_aim_layer, aim_rect);
      layer_set_hidden(s_aim_layer, false);
      s_is_holding_ball = true;
    } else {
      if (hit) {
        s_ball_dir_angle = new_ball_dir_angle;
      }
      ball_animation();
    }
  }
}

static void ball_animation() {
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
  animation_set_duration((Animation*)s_ball_animation, S_BALL_TIME_PER_DIST*rough_dist);
  animation_set_delay((Animation*)s_ball_animation, 0);
  animation_set_curve((Animation*)s_ball_animation, AnimationCurveLinear);
  animation_set_handlers((Animation*)s_ball_animation, (AnimationHandlers) {
    .stopped = ball_anim_stopped_handler
  }, NULL);
  animation_schedule((Animation*)s_ball_animation);

  // Increment stage and wrap
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

static void load_map_from_resource() {
  free_block_array();

  // Get resource and size
  ResHandle handle = resource_get_handle(RESOURCE_ID_MAP1);
  uint8_t res_size = (uint8_t)resource_size(handle);
  uint8_t *buffer = (uint8_t*)malloc(res_size);
  resource_load(handle, buffer, res_size);

  load_map_from_buffer(buffer, res_size);
  free(buffer);
}

static bool load_resume_data_from_persist() {
  if (persist_exists(P_BLOCKS_DATA_KEY)) {
    free_block_array();

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
      s_active_powerup = (PowerupTypeEnum) persist_read_int(P_POWERUP_KEY);
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
    persist_write_int(P_PADDLE_KEY, (int)paddle_frame.origin.x);

    persist_write_int(P_POWERUP_KEY, (int)s_active_powerup);
  }
}

static void game_window_load(Window *window) {
  APP_LOG(APP_LOG_LEVEL_DEBUG, "game load");
  Layer *window_layer = window_get_root_layer(window);
  GRect bounds = layer_get_bounds(window_layer);

  s_main_layer = layer_create((GRect) {
    .origin = {0, 0},
    .size = bounds.size
  });
  layer_add_child(window_layer, s_main_layer);

  s_text_layer = text_layer_create((GRect) {
    .origin = { 0, 10 },
    .size = { bounds.size.w, 20 }
  });
  text_layer_set_text(s_text_layer, "Press a button");
  text_layer_set_text_alignment(s_text_layer, GTextAlignmentCenter);
  layer_add_child(s_main_layer, text_layer_get_layer(s_text_layer));

  int16_t paddle_origin_y = 160;

  s_ball_layer = layer_create((GRect) {
    .origin = {113, paddle_origin_y-5},
    .size = {5, 5}
  });
  layer_set_update_proc(s_ball_layer, ball_layer_draw);
  layer_add_child(s_main_layer, s_ball_layer);

  s_paddle_layer = layer_create((GRect) {
    .origin = {100, paddle_origin_y},
    .size = {PADDLE_WIDTH_STANDARD, 5}
  });
  layer_set_update_proc(s_paddle_layer, paddle_layer_draw);
  layer_add_child(s_main_layer, s_paddle_layer);

  s_aim_layer = layer_create_with_data((GRect) {
    .origin = {100, paddle_origin_y-17},
    .size = {PADDLE_WIDTH_STANDARD, 15}
  }, 2);
  int16_t *aim_angle = layer_get_data(s_aim_layer);
  *aim_angle = -TRIG_MAX_ANGLE/4;
  layer_set_update_proc(s_aim_layer, aim_layer_draw);
  layer_add_child(s_main_layer, s_aim_layer);

  if (is_resume && load_resume_data_from_persist()) {
    s_is_holding_ball = false;
    layer_set_hidden(s_aim_layer, true);
    ball_animation();
  } else {
    load_map_from_resource();

    s_ball_dir_angle = TRIG_MAX_ANGLE/8;
    s_active_powerup = FIRST_BALL_HOLD;
    s_is_holding_ball = true;
  }


  char buffer[8];
  clock_copy_time_string(buffer, 8);
  // APP_LOG(APP_LOG_LEVEL_DEBUG, buffer);
  for (int i = 0; i < 8; i++) {
    if (buffer[i] == ':') {
      srand(buffer[i+2]);
      // text_layer_set_text(s_text_layer, "buffer");
      // APP_LOG(APP_LOG_LEVEL_DEBUG, "minute ones: %d", buffer[i+2]);
      // text_layer_set_text(s_text_layer, buffer);
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

  free_block_array();
  free_powerup_array();
  layer_destroy(s_main_layer);
}

static void menu_new_game_callback(int index, void *context) {
  is_resume = false;
  window_stack_push(s_main_window, true);
}

static void menu_resume_callback(int index, void *context) {
  if (persist_exists(P_BLOCKS_DATA_KEY)) {
    is_resume = true;
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

  free_block_array();

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

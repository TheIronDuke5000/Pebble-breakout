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
static uint16_t s_num_blocks;
static Layer *s_aim_layer;
static bool is_resume;

#define P_PADDLE_KEY 0        // uint8_t for x value of origin of paddle layer
#define P_BALL_KEY 1          // 2 int16_t saved into a single uint32_t for ball origin; x is MSB, y is LSB
#define P_POWERUP_KEY 2       // power_up_type saved as an int
#define P_BLOCKS_DATA_KEY 4   // array of bytes with the same format as the file (HH XX YY) HH is the nubmer of hits remaining

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
} ball_reflection_type;

typedef enum {
  NONE = 0,
  FIRST_BALL_HOLD = 1,
  HOLD = 2,
  LASER = 3,
  WIDE_PADDLE = 4
} power_up_type;

static power_up_type s_power_up;
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

static void ball_animation();

static void select_click_handler(ClickRecognizerRef recognizer, void *context) {
  text_layer_set_text(s_text_layer, "Select");

  if ((s_power_up == HOLD || s_power_up == FIRST_BALL_HOLD) && s_is_holding_ball) {
    layer_set_hidden(s_aim_layer, true);
    int16_t *aim_angle = layer_get_data(s_aim_layer);
    s_ball_dir_angle = *aim_angle;
    s_is_holding_ball = false;
    ball_animation();
  } else if (s_power_up == LASER) {
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
  if ((s_power_up == HOLD || s_power_up == FIRST_BALL_HOLD) && s_is_holding_ball) {
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
    GColor8 paddle_color = GColorDukeBlue;
  #else
    GColor paddle_color = GColorBlack;
  #endif

  graphics_context_set_fill_color(ctx, paddle_color);
  graphics_fill_rect(ctx, bounds, bounds.size.h/2, GCornersAll);
}

static ball_reflection_type ball_reflection(GRect *ball_rect, int16_t *new_ball_dir_angle, bool hit) {
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
    if (ball_dir_abs_x > ball_dir_abs_y) {
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
      if (hit) {
        *new_ball_dir_angle = reflect_angle_Y(*new_ball_dir_angle);
      }
      return WALL_VERT;
    } else if (next_rect.origin.y < 0) {
      if (hit) {
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
      if (hit) {
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
            if (hit) {
              *new_ball_dir_angle = reflect_angle_X(*new_ball_dir_angle);
              (*block_data)--;
              layer_mark_dirty(s_block_layer_array[j]);
            }
            return BLOCK_HORZ;
          } else if (next_rect.origin.y < block_frame.origin.y + block_frame.size.h &&
                     next_rect.origin.y + next_rect.size.h > block_frame.origin.y &&
                     (next_rect.origin.x +1 == block_frame.origin.x + block_frame.size.w ||
                     next_rect.origin.x + next_rect.size.w -1 == block_frame.origin.x)) {
            if (hit) {
              *new_ball_dir_angle = reflect_angle_Y(*new_ball_dir_angle);
              (*block_data)--;
              layer_mark_dirty(s_block_layer_array[j]);
            }
            return BLOCK_VERT;
          }
        }
      }
    }


    *ball_rect = next_rect;
  }
  return NO_REFLECT;
}

static void anim_stopped_handler(Animation *animation, bool finished, void *context) {
  #ifdef PBL_PLATFORM_APLITE
    // Free the animation
    property_animation_destroy(s_ball_animation);
  #endif

  // Schedule the next one, unless the app is exiting
  if (finished) {
    int16_t new_ball_dir_angle;
    GRect ball_rect = layer_get_frame(s_ball_layer);
    ball_reflection_type reflect_type = ball_reflection(&ball_rect, &new_ball_dir_angle, true);
    if (reflect_type == DEATH) {
      text_layer_set_text(s_text_layer, "DEATH");
      window_stack_pop(true);
    } else if (reflect_type == PADDLE_HIT && s_power_up == HOLD) {
      GRect aim_rect = layer_get_frame(s_aim_layer);
      GRect ball_rect = layer_get_frame(s_ball_layer);
      aim_rect.origin.x = ball_rect.origin.x - 13;
      layer_set_frame(s_aim_layer, aim_rect);
      layer_set_hidden(s_aim_layer, false);
      s_is_holding_ball = true;
    } else {
      s_ball_dir_angle = new_ball_dir_angle;
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
  ball_reflection_type reflect_type = ball_reflection(&finish, &new_ball_dir_angle, false);

  int16_t rough_dist = abs(finish.origin.x - start.origin.x) +
                       abs(finish.origin.y - start.origin.y);

  // Schedule the next animation
  s_ball_animation = property_animation_create_layer_frame(s_ball_layer, &start, &finish);
  animation_set_duration((Animation*)s_ball_animation, S_BALL_TIME_PER_DIST*rough_dist);
  animation_set_delay((Animation*)s_ball_animation, 0);
  animation_set_curve((Animation*)s_ball_animation, AnimationCurveLinear);
  animation_set_handlers((Animation*)s_ball_animation, (AnimationHandlers) {
    .stopped = anim_stopped_handler
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

static bool load_map_from_persist() {
  if (persist_exists(P_BLOCKS_DATA_KEY)) {
    free_block_array();

    uint8_t res_size = persist_get_size(P_BLOCKS_DATA_KEY);

    uint8_t *buffer = (uint8_t*)malloc(res_size);
    persist_read_data(P_BLOCKS_DATA_KEY, buffer, res_size);

    load_map_from_buffer(buffer, res_size);
    free(buffer);
    return true;
  } else {
    return false;
  }
}

static void persist_map() {
  uint8_t res_size = s_num_blocks*3;
  char *buffer = (char *)malloc(res_size);

  for (int i = 0; i < s_num_blocks; i++) {
    uint8_t *layer_data = layer_get_data(s_block_layer_array[i]);
    GRect frame = layer_get_frame(s_block_layer_array[i]);
    buffer[i*3] = *layer_data;
    buffer[i*3+1] = frame.origin.x;
    buffer[i*3+2] = frame.origin.y;
  }

  persist_write_data(P_BLOCKS_DATA_KEY, buffer, res_size);
  free(buffer);
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
    .origin = { 0, 72 },
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
    .size = {30, 5}
  });
  layer_set_update_proc(s_paddle_layer, paddle_layer_draw);
  layer_add_child(s_main_layer, s_paddle_layer);

  s_aim_layer = layer_create_with_data((GRect) {
    .origin = {100, paddle_origin_y-17},
    .size = {30, 15}
  }, 2);
  int16_t *aim_angle = layer_get_data(s_aim_layer);
  *aim_angle = -TRIG_MAX_ANGLE/4;
  layer_set_update_proc(s_aim_layer, aim_layer_draw);
  layer_add_child(s_main_layer, s_aim_layer);

  if (is_resume) {
    if (!load_map_from_persist()) {
      // window_stack_pop(true);
    }
  } else {
    load_map_from_resource();
  }

  s_ball_dir_angle = TRIG_MAX_ANGLE/8;

  s_power_up = FIRST_BALL_HOLD;
  s_is_holding_ball = true;

}

static void game_window_unload(Window *window) {
  APP_LOG(APP_LOG_LEVEL_DEBUG, "game unload");

  animation_unschedule_all();

  persist_map();

  layer_destroy((Layer *)s_text_layer);
  layer_destroy(s_ball_layer);
  layer_destroy(s_paddle_layer);
  layer_destroy(s_aim_layer);

  free_block_array();
  layer_destroy(s_main_layer);
}

void menu_new_game_callback(int index, void *context) {
  is_resume = false;
  window_stack_push(s_main_window, true);
}

void menu_resume_callback(int index, void *context) {
  is_resume = true;
  window_stack_push(s_main_window, true);
}

static void menu_window_load(Window *window) {
  Layer *window_layer = window_get_root_layer(window);
  GRect bounds = layer_get_bounds(window_layer);

  s_menu_items[0].title = "New Game";
  s_menu_items[0].callback = menu_new_game_callback;

  s_menu_items[1].title = "Resume";
  s_menu_items[1].callback = menu_resume_callback;

  s_menu_section.items = s_menu_items;
  s_menu_section.num_items = 2;

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

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

static Window *s_main_window;
static Layer *s_main_layer;
static TextLayer *s_text_layer;
static Layer *s_ball_layer;
static int16_t s_ball_dir_angle;
static PropertyAnimation *s_ball_animation;
static Layer *s_paddle_layer;
static int16_t s_paddle_velocity;
static const int16_t S_PADDLE_MAX_SPEED = 8;
static const int16_t S_BALL_TIME_PER_DIST = 10;
static Layer **s_block_layer_array;
static uint16_t s_num_blocks;

typedef enum  {
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

static void select_click_handler(ClickRecognizerRef recognizer, void *context) {
  text_layer_set_text(s_text_layer, "Select");
}

static void move_paddle() {
  GRect frame = layer_get_frame(s_paddle_layer);
  frame.origin.x += s_paddle_velocity;
  layer_set_frame(s_paddle_layer, frame);
  layer_mark_dirty(s_paddle_layer);
}

static void top_btn_rep_handler(ClickRecognizerRef recognizer, void *context) {
  text_layer_set_text(s_text_layer, "Up Press");
  int16_t numClicks = click_number_of_clicks_counted(recognizer);
  if (numClicks == 1) {
    s_paddle_velocity = -S_PADDLE_MAX_SPEED/2;
  } else {
    s_paddle_velocity = -S_PADDLE_MAX_SPEED;
  }
  move_paddle();
}

static void bot_btn_rep_handler(ClickRecognizerRef recognizer, void *context) {
  text_layer_set_text(s_text_layer, "Down Press");
  int16_t numClicks = click_number_of_clicks_counted(recognizer);
  if (numClicks == 1) {
    s_paddle_velocity = S_PADDLE_MAX_SPEED/2;
  } else {
    s_paddle_velocity = S_PADDLE_MAX_SPEED;
  }
  move_paddle();
}

static void click_config_provider(void *context) {
  window_single_click_subscribe(BUTTON_ID_SELECT, select_click_handler);
  window_single_repeating_click_subscribe(BUTTON_ID_UP, 30, top_btn_rep_handler);
  window_single_repeating_click_subscribe(BUTTON_ID_DOWN, 30, bot_btn_rep_handler);
}

static void block_layer_draw(Layer *layer, GContext *ctx) {
  GRect bounds = layer_get_bounds(layer);

  graphics_context_set_fill_color(ctx, GColorBlack);
  graphics_fill_rect(ctx, bounds, 0, GCornersAll);
}

static void ball_layer_draw(Layer *layer, GContext *ctx) {
  GRect bounds = layer_get_bounds(layer);

  graphics_context_set_fill_color(ctx, GColorBlack);
  const int16_t half_h = bounds.size.h / 2;
  graphics_fill_circle(ctx, GPoint(half_h, half_h), half_h);
}

static void paddle_layer_draw(Layer *layer, GContext *ctx) {
  GRect bounds = layer_get_bounds(layer);

  graphics_context_set_fill_color(ctx, GColorBlack);
  graphics_fill_rect(ctx, bounds, bounds.size.h, GCornersAll);
}

static void next_animation();

static ball_reflection_type ball_reflection(GRect *ball_rect, int16_t *new_ball_dir_angle) {
  int i;
  GPoint ball_dir = get_ball_dir_point();
  int16_t ball_dir_abs_x = abs(ball_dir.x);
  int16_t ball_dir_abs_y = abs(ball_dir.y);
  GRect arena_bounds = layer_get_bounds(s_main_layer);
  GRect paddle_frame = layer_get_frame(s_paddle_layer);
  bool maxIsX = (max(ball_dir_abs_x, ball_dir_abs_y) == ball_dir_abs_x);
  GRect init_rect = *ball_rect;
  GRect next_rect = init_rect;
  *new_ball_dir_angle = s_ball_dir_angle;


  for (i = 0; i < 200; i++) {
    if (maxIsX) {
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
      *new_ball_dir_angle = reflect_angle_Y(*new_ball_dir_angle);
      return WALL_VERT;
    } else if (next_rect.origin.y < 0) {
      *new_ball_dir_angle = reflect_angle_X(*new_ball_dir_angle);
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
      *new_ball_dir_angle = reflect_angle_X(*new_ball_dir_angle);
      int16_t dist_from_centre = (next_rect.origin.x + next_rect.size.w/2) -
                                 (paddle_frame.origin.x + paddle_frame.size.w/2);
      int16_t angle_diff = (TRIG_MAX_ANGLE/16 * dist_from_centre*2) / paddle_frame.size.w;
      *new_ball_dir_angle += angle_diff;
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
        block_data = layer_get_data(s_block_layer_array[j]);
        is_block_alive = (*block_data) > 0;
        if (is_block_alive) {
          block_frame = layer_get_frame(s_block_layer_array[j]);
          if ((next_rect.origin.y == block_frame.origin.y + block_frame.size.h ||
               next_rect.origin.y + next_rect.size.h == block_frame.origin.y) &&
              next_rect.origin.x < block_frame.origin.x + block_frame.size.w &&
              next_rect.origin.x + next_rect.size.w > block_frame.origin.x) {
            *new_ball_dir_angle = reflect_angle_X(*new_ball_dir_angle);
            return BLOCK_HORZ;
          } else if (next_rect.origin.y < block_frame.origin.y + block_frame.size.h &&
                     next_rect.origin.y + next_rect.size.h > block_frame.origin.y &&
                     (next_rect.origin.x == block_frame.origin.x + block_frame.size.w ||
                     next_rect.origin.x + next_rect.size.w == block_frame.origin.x)) {
            *new_ball_dir_angle = reflect_angle_Y(*new_ball_dir_angle);
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
    ball_reflection_type reflect_type = ball_reflection(&ball_rect, &new_ball_dir_angle);
    if (reflect_type == DEATH) {
      text_layer_set_text(s_text_layer, "DEATH");
    } else {
      s_ball_dir_angle = new_ball_dir_angle;
      next_animation();
    }
  }
}

static void next_animation() {
  // Determine start and finish positions
  GRect start, finish;
  int16_t new_ball_dir_angle;

  start = layer_get_frame(s_ball_layer);
  finish = start;

  int i;
  ball_reflection_type reflect_type = ball_reflection(&finish, &new_ball_dir_angle);

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

static void load_map_from_file() {
  // Get resource and size
  ResHandle handle = resource_get_handle(RESOURCE_ID_MAP1);
  size_t res_size = resource_size(handle);

  // Copy to buffer
  char *s_buffer = (char*)malloc(res_size);
  resource_load(handle, (uint8_t*)s_buffer, res_size);

  s_num_blocks = res_size / 3;

  free(s_block_layer_array);
  s_block_layer_array = NULL;

  s_block_layer_array = (Layer **)malloc(s_num_blocks*(sizeof(Layer *)));

  GRect block_rect = (GRect) { .origin = {0, 0}, .size = {10, 5}};

  // create blocks
  int16_t i;
  for (i = 0; i < s_num_blocks; i++) {
    block_rect.origin.x = s_buffer[i*3 + 1];
    block_rect.origin.y = s_buffer[i*3 + 2];
    Layer *new_block_layer = layer_create_with_data(block_rect, 1);
    uint8_t *layer_data = (uint8_t *)layer_get_data(new_block_layer);
    *layer_data = s_buffer[i*3];
    layer_set_update_proc(new_block_layer, block_layer_draw);
    layer_add_child(s_main_layer, new_block_layer);
    s_block_layer_array[i] = new_block_layer;
  }
}

static void window_load(Window *window) {
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

  s_ball_layer = layer_create((GRect) { .origin = {10, 20}, .size = {5, 5} });
  layer_set_update_proc(s_ball_layer, ball_layer_draw);
  layer_add_child(s_main_layer, s_ball_layer);

  s_paddle_layer = layer_create((GRect) { .origin = {100, 160}, .size = {30, 5} });
  layer_set_update_proc(s_paddle_layer, paddle_layer_draw);
  layer_add_child(s_main_layer, s_paddle_layer);

  load_map_from_file();
}

static void window_unload(Window *window) {
  layer_destroy(s_main_layer);
}

static void init(void) {
  s_main_window = window_create();
  window_set_click_config_provider(s_main_window, click_config_provider);
  window_set_window_handlers(s_main_window, (WindowHandlers) {
    .load = window_load,
    .unload = window_unload,
  });
  const bool animated = true;
  window_stack_push(s_main_window, animated);

  s_ball_dir_angle = TRIG_MAX_ANGLE/8;

  next_animation();
}

static void deinit(void) {
  // Stop any animation in progress
  animation_unschedule_all();

  // Destroy main Window
  window_destroy(s_main_window);
}

int main(void) {
  init();

  APP_LOG(APP_LOG_LEVEL_DEBUG, "Done initializing, pushed window: %p", s_main_window);

  app_event_loop();
  deinit();
}

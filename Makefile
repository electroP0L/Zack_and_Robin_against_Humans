CPP=g++
LD=g++



CPPFLAGS= -Ideps/include -std=c++14 -g
LDFLAGS= -Ldeps/lib -lSDL2main -lSDL2 -lSDL2_image


OBJECTS = main.o zombie.o
all: ZandRVSH

ZandRVSH: $(OBJECTS)
	$(LD)	-o ZandRVSH	$(OBJECTS)	$(LDFLAGS)


main.o: main.cpp zombie.hpp region.hpp tree.hpp rock.hpp command.hpp
	$(CPP)	-c main.cpp	$(CPPFLAGS)


command.o: command.hpp obstacle.hpp

entity.o: entity.hpp

living.o: living.hpp entity.hpp command.hpp

zombie.o: zombie.cpp zombie.hpp living.hpp
	$(CPP)	-c zombie.cpp	$(CPPFLAGS)

obstacle.o: obstacle.hpp entity.hpp

rock.o: rock.hpp obstacle.hpp

tree.o: tree.hpp obstacle.hpp

region.o: region.hpp obstacle.hpp

clean:
	rm -f *.o ZandRVSH

# DO NOT DELETE

main.o: /usr/include/stdlib.h /usr/include/time.h /usr/include/features.h
main.o: /usr/include/features-time64.h /usr/include/stdc-predef.h zombie.hpp
main.o: living.hpp entity.hpp /usr/include/SDL2/SDL.h
main.o: /usr/include/SDL2/SDL_main.h /usr/include/SDL2/SDL_stdinc.h
main.o: /usr/include/SDL2/SDL_config.h /usr/include/SDL2/begin_code.h
main.o: /usr/include/SDL2/close_code.h /usr/include/SDL2/SDL_assert.h
main.o: /usr/include/SDL2/SDL_atomic.h /usr/include/SDL2/SDL_platform.h
main.o: /usr/include/SDL2/SDL_audio.h /usr/include/SDL2/SDL_error.h
main.o: /usr/include/SDL2/SDL_endian.h /usr/include/SDL2/SDL_mutex.h
main.o: /usr/include/SDL2/SDL_thread.h /usr/include/SDL2/SDL_rwops.h
main.o: /usr/include/SDL2/SDL_clipboard.h /usr/include/SDL2/SDL_cpuinfo.h
main.o: /usr/include/SDL2/SDL_events.h /usr/include/SDL2/SDL_video.h
main.o: /usr/include/SDL2/SDL_pixels.h /usr/include/SDL2/SDL_rect.h
main.o: /usr/include/SDL2/SDL_surface.h /usr/include/SDL2/SDL_blendmode.h
main.o: /usr/include/SDL2/SDL_keyboard.h /usr/include/SDL2/SDL_keycode.h
main.o: /usr/include/SDL2/SDL_scancode.h /usr/include/SDL2/SDL_mouse.h
main.o: /usr/include/SDL2/SDL_joystick.h
main.o: /usr/include/SDL2/SDL_gamecontroller.h /usr/include/SDL2/SDL_sensor.h
main.o: /usr/include/SDL2/SDL_quit.h /usr/include/SDL2/SDL_gesture.h
main.o: /usr/include/SDL2/SDL_touch.h /usr/include/SDL2/SDL_filesystem.h
main.o: /usr/include/SDL2/SDL_haptic.h /usr/include/SDL2/SDL_hidapi.h
main.o: /usr/include/SDL2/SDL_hints.h /usr/include/SDL2/SDL_loadso.h
main.o: /usr/include/SDL2/SDL_log.h /usr/include/SDL2/SDL_messagebox.h
main.o: /usr/include/SDL2/SDL_metal.h /usr/include/SDL2/SDL_power.h
main.o: /usr/include/SDL2/SDL_render.h /usr/include/SDL2/SDL_shape.h
main.o: /usr/include/SDL2/SDL_system.h /usr/include/SDL2/SDL_timer.h
main.o: /usr/include/SDL2/SDL_version.h /usr/include/SDL2/SDL_locale.h
main.o: /usr/include/SDL2/SDL_misc.h /usr/include/SDL2/SDL_image.h
main.o: /usr/include/SDL2/SDL.h /usr/include/SDL2/SDL_timer.h command.hpp
main.o: obstacle.hpp region.hpp tree.hpp rock.hpp
zombie.o: zombie.hpp living.hpp entity.hpp /usr/include/SDL2/SDL.h
zombie.o: /usr/include/SDL2/SDL_main.h /usr/include/SDL2/SDL_stdinc.h
zombie.o: /usr/include/SDL2/SDL_config.h /usr/include/SDL2/begin_code.h
zombie.o: /usr/include/SDL2/close_code.h /usr/include/SDL2/SDL_assert.h
zombie.o: /usr/include/SDL2/SDL_atomic.h /usr/include/SDL2/SDL_platform.h
zombie.o: /usr/include/SDL2/SDL_audio.h /usr/include/SDL2/SDL_error.h
zombie.o: /usr/include/SDL2/SDL_endian.h /usr/include/SDL2/SDL_mutex.h
zombie.o: /usr/include/SDL2/SDL_thread.h /usr/include/SDL2/SDL_rwops.h
zombie.o: /usr/include/SDL2/SDL_clipboard.h /usr/include/SDL2/SDL_cpuinfo.h
zombie.o: /usr/include/SDL2/SDL_events.h /usr/include/SDL2/SDL_video.h
zombie.o: /usr/include/SDL2/SDL_pixels.h /usr/include/SDL2/SDL_rect.h
zombie.o: /usr/include/SDL2/SDL_surface.h /usr/include/SDL2/SDL_blendmode.h
zombie.o: /usr/include/SDL2/SDL_keyboard.h /usr/include/SDL2/SDL_keycode.h
zombie.o: /usr/include/SDL2/SDL_scancode.h /usr/include/SDL2/SDL_mouse.h
zombie.o: /usr/include/SDL2/SDL_joystick.h
zombie.o: /usr/include/SDL2/SDL_gamecontroller.h
zombie.o: /usr/include/SDL2/SDL_sensor.h /usr/include/SDL2/SDL_quit.h
zombie.o: /usr/include/SDL2/SDL_gesture.h /usr/include/SDL2/SDL_touch.h
zombie.o: /usr/include/SDL2/SDL_filesystem.h /usr/include/SDL2/SDL_haptic.h
zombie.o: /usr/include/SDL2/SDL_hidapi.h /usr/include/SDL2/SDL_hints.h
zombie.o: /usr/include/SDL2/SDL_loadso.h /usr/include/SDL2/SDL_log.h
zombie.o: /usr/include/SDL2/SDL_messagebox.h /usr/include/SDL2/SDL_metal.h
zombie.o: /usr/include/SDL2/SDL_power.h /usr/include/SDL2/SDL_render.h
zombie.o: /usr/include/SDL2/SDL_shape.h /usr/include/SDL2/SDL_system.h
zombie.o: /usr/include/SDL2/SDL_timer.h /usr/include/SDL2/SDL_version.h
zombie.o: /usr/include/SDL2/SDL_locale.h /usr/include/SDL2/SDL_misc.h
zombie.o: /usr/include/SDL2/SDL_image.h /usr/include/SDL2/SDL.h
zombie.o: /usr/include/SDL2/SDL_timer.h command.hpp obstacle.hpp

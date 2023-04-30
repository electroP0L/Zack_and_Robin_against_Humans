CPP=g++
LD=g++



CPPFLAGS= -Ideps/include -std=c++14 -g
LDFLAGS= -Ldeps/lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-network -lsfml-audio


OBJECTS = main.o living.o zombie.o robot.o map.o
all: ZandRVSH

ZandRVSH: $(OBJECTS)
	$(LD)	-o ZandRVSH	$(OBJECTS)	$(LDFLAGS)


main.o: main.cpp zombie.hpp robot.hpp map.hpp contexte.hpp
	$(CPP)	-c main.cpp	$(CPPFLAGS)


contexte.o: contexte.hpp region.hpp obstacle.hpp

entity.o: entity.hpp

living.o: living.cpp living.hpp entity.hpp contexte.hpp
	$(CPP)	-c living.cpp	$(CPPFLAGS)


zombie.o: zombie.cpp zombie.hpp living.hpp
	$(CPP)	-c zombie.cpp	$(CPPFLAGS)

robot.o: robot.cpp robot.hpp living.hpp
	$(CPP)	-c robot.cpp	$(CPPFLAGS)

obstacle.o: obstacle.hpp entity.hpp

rock.o: rock.hpp obstacle.hpp

tree.o: tree.hpp obstacle.hpp

fence.o: fence.hpp obstacle.hpp

map.o: map.cpp region.hpp zombie.hpp robot.hpp tree.hpp rock.hpp fence.hpp
	$(CPP)	-c map.cpp	$(CPPFLAGS)

region.o: region.hpp obstacle.hpp

clean:
	rm -f *.o ZandRVSH

# DO NOT DELETE

main.o: /usr/include/stdlib.h /usr/include/time.h /usr/include/features.h
main.o: /usr/include/features-time64.h /usr/include/stdc-predef.h zombie.hpp
main.o: living.hpp entity.hpp /usr/include/SFML/Graphics.hpp
main.o: /usr/include/SFML/Window.hpp /usr/include/SFML/System.hpp
main.o: /usr/include/SFML/Config.hpp /usr/include/SFML/System/Clock.hpp
main.o: /usr/include/SFML/System/Export.hpp /usr/include/SFML/System/Time.hpp
main.o: /usr/include/SFML/System/Err.hpp
main.o: /usr/include/SFML/System/FileInputStream.hpp
main.o: /usr/include/SFML/System/InputStream.hpp
main.o: /usr/include/SFML/System/NonCopyable.hpp
main.o: /usr/include/SFML/System/Lock.hpp
main.o: /usr/include/SFML/System/MemoryInputStream.hpp
main.o: /usr/include/SFML/System/Mutex.hpp /usr/include/SFML/System/Sleep.hpp
main.o: /usr/include/SFML/System/String.hpp /usr/include/SFML/System/Utf.hpp
main.o: /usr/include/SFML/System/Utf.inl /usr/include/SFML/System/String.inl
main.o: /usr/include/SFML/System/Thread.hpp
main.o: /usr/include/SFML/System/Thread.inl
main.o: /usr/include/SFML/System/ThreadLocal.hpp
main.o: /usr/include/SFML/System/ThreadLocalPtr.hpp
main.o: /usr/include/SFML/System/ThreadLocalPtr.inl
main.o: /usr/include/SFML/System/Vector2.hpp
main.o: /usr/include/SFML/System/Vector2.inl
main.o: /usr/include/SFML/System/Vector3.hpp
main.o: /usr/include/SFML/System/Vector3.inl
main.o: /usr/include/SFML/Window/Clipboard.hpp
main.o: /usr/include/SFML/Window/Export.hpp
main.o: /usr/include/SFML/Window/Context.hpp
main.o: /usr/include/SFML/Window/GlResource.hpp
main.o: /usr/include/SFML/Window/ContextSettings.hpp
main.o: /usr/include/SFML/Window/Cursor.hpp
main.o: /usr/include/SFML/Window/Event.hpp
main.o: /usr/include/SFML/Window/Joystick.hpp
main.o: /usr/include/SFML/Window/Keyboard.hpp
main.o: /usr/include/SFML/Window/Mouse.hpp
main.o: /usr/include/SFML/Window/Sensor.hpp
main.o: /usr/include/SFML/Window/Touch.hpp
main.o: /usr/include/SFML/Window/VideoMode.hpp
main.o: /usr/include/SFML/Window/Window.hpp
main.o: /usr/include/SFML/Window/WindowHandle.hpp
main.o: /usr/include/SFML/Window/WindowStyle.hpp
main.o: /usr/include/SFML/Graphics/BlendMode.hpp
main.o: /usr/include/SFML/Graphics/Export.hpp
main.o: /usr/include/SFML/Graphics/CircleShape.hpp
main.o: /usr/include/SFML/Graphics/Shape.hpp
main.o: /usr/include/SFML/Graphics/Drawable.hpp
main.o: /usr/include/SFML/Graphics/RenderStates.hpp
main.o: /usr/include/SFML/Graphics/Transform.hpp
main.o: /usr/include/SFML/Graphics/Rect.hpp
main.o: /usr/include/SFML/Graphics/Rect.inl
main.o: /usr/include/SFML/Graphics/Transformable.hpp
main.o: /usr/include/SFML/Graphics/VertexArray.hpp
main.o: /usr/include/SFML/Graphics/Vertex.hpp
main.o: /usr/include/SFML/Graphics/Color.hpp
main.o: /usr/include/SFML/Graphics/PrimitiveType.hpp
main.o: /usr/include/SFML/Graphics/ConvexShape.hpp
main.o: /usr/include/SFML/Graphics/Font.hpp
main.o: /usr/include/SFML/Graphics/Glyph.hpp
main.o: /usr/include/SFML/Graphics/Texture.hpp
main.o: /usr/include/SFML/Graphics/Image.hpp
main.o: /usr/include/SFML/Graphics/RectangleShape.hpp
main.o: /usr/include/SFML/Graphics/RenderTarget.hpp
main.o: /usr/include/SFML/Graphics/View.hpp
main.o: /usr/include/SFML/Graphics/RenderTexture.hpp
main.o: /usr/include/SFML/Graphics/RenderWindow.hpp
main.o: /usr/include/SFML/Graphics/Shader.hpp
main.o: /usr/include/SFML/Graphics/Glsl.hpp
main.o: /usr/include/SFML/Graphics/Glsl.inl
main.o: /usr/include/SFML/Graphics/Sprite.hpp
main.o: /usr/include/SFML/Graphics/Text.hpp
main.o: /usr/include/SFML/Graphics/VertexBuffer.hpp contexte.hpp obstacle.hpp
main.o: region.hpp tree.hpp rock.hpp
zombie.o: zombie.hpp living.hpp entity.hpp /usr/include/SFML/Graphics.hpp
zombie.o: /usr/include/SFML/Window.hpp /usr/include/SFML/System.hpp
zombie.o: /usr/include/SFML/Config.hpp /usr/include/SFML/System/Clock.hpp
zombie.o: /usr/include/SFML/System/Export.hpp
zombie.o: /usr/include/SFML/System/Time.hpp /usr/include/SFML/System/Err.hpp
zombie.o: /usr/include/SFML/System/FileInputStream.hpp
zombie.o: /usr/include/SFML/System/InputStream.hpp
zombie.o: /usr/include/SFML/System/NonCopyable.hpp
zombie.o: /usr/include/SFML/System/Lock.hpp
zombie.o: /usr/include/SFML/System/MemoryInputStream.hpp
zombie.o: /usr/include/SFML/System/Mutex.hpp
zombie.o: /usr/include/SFML/System/Sleep.hpp
zombie.o: /usr/include/SFML/System/String.hpp
zombie.o: /usr/include/SFML/System/Utf.hpp /usr/include/SFML/System/Utf.inl
zombie.o: /usr/include/SFML/System/String.inl
zombie.o: /usr/include/SFML/System/Thread.hpp
zombie.o: /usr/include/SFML/System/Thread.inl
zombie.o: /usr/include/SFML/System/ThreadLocal.hpp
zombie.o: /usr/include/SFML/System/ThreadLocalPtr.hpp
zombie.o: /usr/include/SFML/System/ThreadLocalPtr.inl
zombie.o: /usr/include/SFML/System/Vector2.hpp
zombie.o: /usr/include/SFML/System/Vector2.inl
zombie.o: /usr/include/SFML/System/Vector3.hpp
zombie.o: /usr/include/SFML/System/Vector3.inl
zombie.o: /usr/include/SFML/Window/Clipboard.hpp
zombie.o: /usr/include/SFML/Window/Export.hpp
zombie.o: /usr/include/SFML/Window/Context.hpp
zombie.o: /usr/include/SFML/Window/GlResource.hpp
zombie.o: /usr/include/SFML/Window/ContextSettings.hpp
zombie.o: /usr/include/SFML/Window/Cursor.hpp
zombie.o: /usr/include/SFML/Window/Event.hpp
zombie.o: /usr/include/SFML/Window/Joystick.hpp
zombie.o: /usr/include/SFML/Window/Keyboard.hpp
zombie.o: /usr/include/SFML/Window/Mouse.hpp
zombie.o: /usr/include/SFML/Window/Sensor.hpp
zombie.o: /usr/include/SFML/Window/Touch.hpp
zombie.o: /usr/include/SFML/Window/VideoMode.hpp
zombie.o: /usr/include/SFML/Window/Window.hpp
zombie.o: /usr/include/SFML/Window/WindowHandle.hpp
zombie.o: /usr/include/SFML/Window/WindowStyle.hpp
zombie.o: /usr/include/SFML/Graphics/BlendMode.hpp
zombie.o: /usr/include/SFML/Graphics/Export.hpp
zombie.o: /usr/include/SFML/Graphics/CircleShape.hpp
zombie.o: /usr/include/SFML/Graphics/Shape.hpp
zombie.o: /usr/include/SFML/Graphics/Drawable.hpp
zombie.o: /usr/include/SFML/Graphics/RenderStates.hpp
zombie.o: /usr/include/SFML/Graphics/Transform.hpp
zombie.o: /usr/include/SFML/Graphics/Rect.hpp
zombie.o: /usr/include/SFML/Graphics/Rect.inl
zombie.o: /usr/include/SFML/Graphics/Transformable.hpp
zombie.o: /usr/include/SFML/Graphics/VertexArray.hpp
zombie.o: /usr/include/SFML/Graphics/Vertex.hpp
zombie.o: /usr/include/SFML/Graphics/Color.hpp
zombie.o: /usr/include/SFML/Graphics/PrimitiveType.hpp
zombie.o: /usr/include/SFML/Graphics/ConvexShape.hpp
zombie.o: /usr/include/SFML/Graphics/Font.hpp
zombie.o: /usr/include/SFML/Graphics/Glyph.hpp
zombie.o: /usr/include/SFML/Graphics/Texture.hpp
zombie.o: /usr/include/SFML/Graphics/Image.hpp
zombie.o: /usr/include/SFML/Graphics/RectangleShape.hpp
zombie.o: /usr/include/SFML/Graphics/RenderTarget.hpp
zombie.o: /usr/include/SFML/Graphics/View.hpp
zombie.o: /usr/include/SFML/Graphics/RenderTexture.hpp
zombie.o: /usr/include/SFML/Graphics/RenderWindow.hpp
zombie.o: /usr/include/SFML/Graphics/Shader.hpp
zombie.o: /usr/include/SFML/Graphics/Glsl.hpp
zombie.o: /usr/include/SFML/Graphics/Glsl.inl
zombie.o: /usr/include/SFML/Graphics/Sprite.hpp
zombie.o: /usr/include/SFML/Graphics/Text.hpp
zombie.o: /usr/include/SFML/Graphics/VertexBuffer.hpp contexte.hpp
zombie.o: obstacle.hpp

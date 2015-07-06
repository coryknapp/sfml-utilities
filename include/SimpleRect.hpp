#ifndef SIMPLERECT_HPP_ZRP8OZEM
#define SIMPLERECT_HPP_ZRP8OZEM


#include <SFML/Graphics.hpp>
#include <cmath>

using namespace sf;

namespace sfu{

// some new types that can be useful
// For example, I made this while unaware of sf::Rect.
template<typename T>
struct SimpleRectangle{

	Vector2<T> position;
	Vector2<T> size;

	SimpleRectangle() = default;
	SimpleRectangle( const RectangleShape &rect ){
		position = convertVector2<float, T>(rect.getPosition());
		size = convertVector2<float, T>(rect.getSize());
	}
	SimpleRectangle( const Rect<T> &rect ){
		position.x = rect.left;
		position.y = rect.top;
		size.x = rect.width;
		size.y = rect.height;
	}
	operator RectangleShape(){
		RectangleShape rect;
		rect.setPosition( convertVector2<T, float>( position ) );
		rect.setSize( convertVector2<T, float>( size ) );
		return rect;
	}
	operator Rect<T>(){
		RectangleShape rect;
		rect.setPosition( convertVector2<T, float>( position ) );
		rect.setSize( convertVector2<T, float>( size ) );
		return rect;
	}
};

template<typename T>
SimpleRectangle<T> intersection(	const SimpleRectangle<T> &one,
									const SimpleRectangle<T> &two ){
	T oneLeft = one.position.x;
	T oneRight = one.position.x + one.size.x;
	T oneBottom = one.position.y;
	T oneTop = one.position.y + one.size.y;

	T twoLeft = two.position.x;
	T twoRight = two.position.x + two.size.x;
	T twoBottom = two.position.y;
	T twoTop = two.position.y + two.size.y;

	SimpleRectangle<T> returnable;
	auto positiveOrZero = [](T v){ return v > 0 ? v : 0; };
	if( oneLeft < twoLeft ){
		// then one is left of two
		returnable.position.x = twoLeft;
		returnable.size.x = positiveOrZero( twoRight - oneLeft );
	} else { // two is left of one
		returnable.position.x = oneLeft;
		returnable.size.x = positiveOrZero( oneLeft - twoRight );
	}
	if( oneTop < twoTop ){
		// then one is ontop of two
		returnable.position.y = twoTop;
		returnable.size.y = positiveOrZero( twoBottom - oneBottom );
	} else { // two is left of one
		returnable.position.y = oneTop;
		returnable.size.y = positiveOrZero( oneBottom - twoBottom );
	}
	return returnable;
}

#endif


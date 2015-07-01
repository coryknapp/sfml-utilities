#ifndef SFML_UTILITIES_HPP
#define SFML_UTILITIES_HPP

#include <SFML/Graphics.hpp>
#include <cmath>

using namespace sf;

namespace sfu{

template< typename IN, typename OUT >
static inline Vector2<OUT> convertVector2( const Vector2<IN> &vec ) {
	return Vector2<OUT>( (IN)vec.x, (IN)vec.y );
}
	
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

template< typename T>
static inline RectangleShape getRectForCorners( Vector2<T> one, Vector2<T> two ){
	RectangleShape rect;
	rect.setPosition( std::min( one.x, two.x), std::min( one.y, two.y ) );
	rect.setSize( Vector2f( fabs( one.x - two.x ), fabs( one.y - two.y ) ) );
	return rect;
}

static inline char quadrant( sf::Vector2f v ){
	if( v.x > 0 ){ // I or VI
		if( v.y > 0 )
			return 1; // I
		return 4;
	} else { // II or III
		if( v.y > 0 )
			return 2;
		return 3;
	}
}

static inline float angleOff0( sf::Vector2f v ){
	float atan = atanf( v.y / v.x );
	
	auto quad = quadrant( v );
	switch( quad ){
		case 2:
		case 3:
			atan += M_PI;
			break;
	}
	return atan;
}

static inline float angleBetween( sf::Vector2f a, sf::Vector2f b ){
	return angleOff0( b ) - angleOff0( a );
}

static inline sf::Vector2f vectorForAngleFrom0( float rads ){
	return sf::Vector2f( cosf( rads), sinf( rads ) );
}

template <typename T>
static inline float distance( const sf::Vector2<T> &a, const sf::Vector2<T> &b ){
	return sqrt( pow( a.x - b.x, 2) + pow( a.y - b.y, 2 ) );
}

}//namespace sfu
#endif

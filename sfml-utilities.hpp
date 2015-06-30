#ifndef SFML_UTILITIES_HPP
#define SFML_UTILITIES_HPP

#include <SFML/Graphics.hpp>
#include <cmath>

using namespace sf;

namespace sfu{

template< typename IN, typename OUT >
Vector2<OUT> convertVector2( const Vector2<IN> &vec ) {
	return Vector2<OUT>( (IN)vec.x, (IN)vec.y ); 
}

RectangleShape getRectForCorners( Vector2f one, Vector2f two ){
	RectangleShape rect;
	rect.setPosition( std::min( one.x, two.x), std::min( one.y, two.y ) );
	rect.setSize( Vector2f( fabs( one.x - two.x ), fabs( one.y - two.y ) ) );
	return rect;
}

char quadrant( sf::Vector2f v ){
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

float angleOff0( sf::Vector2f v ){
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

float angleBetween( sf::Vector2f a, sf::Vector2f b ){
	return angleOff0( b ) - angleOff0( a );
}

sf::Vector2f vectorForAngleFrom0( float rads ){
	return sf::Vector2f( cosf( rads), sinf( rads ) );
}

template <typename T>
float distance( const sf::Vector2<T> &a, const sf::Vector2<T> &b ){
	return sqrt( pow( a.x - b.x, 2) + pow( a.y - b.y, 2 ) );
}

}//namespace sfu
#endif

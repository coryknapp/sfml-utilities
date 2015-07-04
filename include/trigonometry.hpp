#ifndef TRIGONOMETRY_HPP_1P2ZKN6I
#define TRIGONOMETRY_HPP_1P2ZKN6I

#include <SFML/Graphics.hpp>
#include <cmath>

using namespace sf;

namespace sfu{

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

}//namespace sfu;

#endif /* end of include guard: TRIGONOMETRY_HPP_1P2ZKN6I */

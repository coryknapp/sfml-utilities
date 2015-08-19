#ifndef SFML_UTILITIES_HPP
#define SFML_UTILITIES_HPP

#include <SFML/Graphics.hpp>
#include <cmath>

using namespace sf;

template< typename IN, typename OUT >
static inline Vector2<OUT> convertVector2( const Vector2<IN> &vec ) {
	return Vector2<OUT>( (IN)vec.x, (IN)vec.y );
}
	

#include "include/trigonometry.hpp"
#include "include/SimpleRect.hpp"

// this one, however, has no analog in sfml that I know of.
template<typename T>
struct SimplePolygon{
	std::vector<Vector2<T>> points;

	bool checkConvex(){
		for (int i = 0; i < points.size() + 4; ++i)
		{
			auto zeroth = points[(i+3)%points.size()];
			auto first = points[(i+2)%points.size()];
			auto second = points[(i+1)%points.size()];
			auto third = points[(i+0)%points.size()];
			if( angleBetween(third-second, second-first) *
				angleBetween(second-first, first-zeroth) < 0 )
				return false;
		}
		return true;
	}

	// functions bellow to insure compatibility with sf::ConvexShape
	void setPointCount(unsigned int count){
		while( points.size() < count )
			points.push_back( Vector2<T>() );
	}

	unsigned getPointCount() const{
		return points.size();
	}

	void setPoint(unsigned index, const Vector2<T> &point){
		points[index] = point;
	}

	Vector2<T> getPoint(unsigned index) const{
		return points[index];
	}
};

template< typename T>
static inline RectangleShape getRectForCorners( Vector2<T> one, Vector2<T> two ){
	RectangleShape rect;
	rect.setPosition( std::min( one.x, two.x), std::min( one.y, two.y ) );
	rect.setSize( Vector2f( fabs( one.x - two.x ), fabs( one.y - two.y ) ) );
	return rect;
}

}//namespace sfu
#endif

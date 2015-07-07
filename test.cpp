#include "sfml-utilities.hpp"

#define CATCH_CONFIG_MAIN
#include "/Users/cknapp/Code/Catch/single_include/catch.hpp"

using namespace sfu;
using namespace sf;


TEST_CASE( "SimpleRectangle", "[simplerectangle]" ) {

	SimpleRectangle<int> one;
	SimpleRectangle<int> two;
	SECTION( "no intersection" ) {	
		one.position = Vector2i( 0, 0 );
		two.position = Vector2i( 4, 0 );
		one.size = Vector2i( 2, 2 );
		two.size = Vector2i( 2, 2 );

		REQUIRE( intersection(one, two).size.x == 0 );		
		REQUIRE( intersection(one, two).size.y == 0 );		
	}

	SECTION( "asymmetrical intersection" ) {	
		one.position = Vector2i( 0, 0 );
		two.position = Vector2i( 1, 1 );
		one.size = Vector2i( 2, 2 );
		two.size = Vector2i( 2, 2 );

		REQUIRE( intersection(one, two).size.x == 1 );		
		REQUIRE( intersection(one, two).size.y == 1 );		
		REQUIRE( intersection(one, two).position.x == 1 );		
		REQUIRE( intersection(one, two).position.y == 1 );
		
		REQUIRE( intersection(one, two).size.x == 1 );		
		REQUIRE( intersection(one, two).size.y == 1 );		
		REQUIRE( intersection(one, two).position.x == 1 );		
		REQUIRE( intersection(one, two).position.y == 1 );		
	}

	SECTION( "symmetrical intersection" ) {	
		one.position = Vector2i( 0, 0 );
		two.position = Vector2i( 1, 0 );
		one.size = Vector2i( 2, 2 );
		two.size = Vector2i( 2, 2 );

		REQUIRE( intersection(one, two).size.x == 1 );		
		REQUIRE( intersection(one, two).size.y == 2 );		
		REQUIRE( intersection(one, two).position.x == 1 );		
		REQUIRE( intersection(one, two).position.y == 0 );	
	}

}

TEST_CASE( "SimplePolygon", "[simplepolygon]" ) {

	SimplePolygon<float> convexPoly;
	convexPoly.setPointCount( 4 );

    SECTION( "Clockwise convex check" ) {	
		convexPoly.setPoint( 0, Vector2f( 0, 0 ) );
		convexPoly.setPoint( 1, Vector2f( 0, 1 ) );
		convexPoly.setPoint( 2, Vector2f( 1, 1 ) );
		convexPoly.setPoint( 3, Vector2f( 1, 0 ) );

		REQUIRE( convexPoly.checkConvex() == true );
	}

    SECTION( "Counter clockwise convex check" ) {	
		convexPoly.setPoint( 0, Vector2f( 0, 0 ) );
		convexPoly.setPoint( 1, Vector2f( 1, 0 ) );
		convexPoly.setPoint( 2, Vector2f( 1, 1 ) );
		convexPoly.setPoint( 3, Vector2f( 0, 1 ) );

		REQUIRE( convexPoly.checkConvex() == true );
	}

    SECTION( "Convex check, false" ) {	
		convexPoly.setPoint( 0, Vector2f( 0, 0 ) );
		convexPoly.setPoint( 1, Vector2f( 2, 0 ) );
		convexPoly.setPoint( 2, Vector2f( 1, 1 ) );
		convexPoly.setPoint( 3, Vector2f( 0, 2 ) );

		REQUIRE( convexPoly.checkConvex() == false );
	}


}

#include "sfml-utilities.hpp"

#define CATCH_CONFIG_MAIN
#include "/Users/cknapp/Code/Catch/single_include/catch.hpp"

using namespace sfu;
using namespace sf;

TEST_CASE( "SimplePolygon checkConvex", "[simplepolygon]" ) {

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

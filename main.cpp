//------------------------------
//  DO NOT MODIFY NEXT LINE
//------------------------------
#include "catch.hpp"
//------------------------------

// Use this enum class for indicating the lat/long direction
enum class Compass {N,S,W,E};

// Write your code here

class GPS {
private: 
  double latitude{0.0};
  double longitude{0.0};
  Compass LatitudeDirection{Compass::N}; 
  Compass LongitudeDirection{Compass::W}; 

public:
GPS(){ 
  latitude=0.0;
  LatitudeDirection=Compass::N;
  longitude=0.0;
  LongitudeDirection= Compass::W;
};
GPS(double lat, double lon){
  if ((0<=lat)&& (lat<=90))
  latitude=lat;
  else 
  latitude =0.0;
  LatitudeDirection=Compass::N;

   if ((0<=lon)&& (lon<=180))
 longitude=lon;
  else 
  longitude =0.0;
  LongitudeDirection= Compass::W;
}; 
 
GPS(double lat, Compass latd, double lon, Compass lond){
  if ((0<=lat)&& (lat<=90))
  latitude=lat;
  else 
  latitude =0.0;
  if (latd== Compass::N || latd == Compass::S)
    LatitudeDirection=latd;
    else 
  LatitudeDirection=Compass::N;



  if ((0<=lon)&& (lon<=180))
 longitude=lon;
  else 
  longitude =0.0;
  if(lond == Compass::W || lond== Compass:: E)
  LongitudeDirection = lond; 
  else 
 LongitudeDirection= Compass::W;
};

double getLongitude(){return longitude;}
double getLatitude(){return latitude;} 
Compass getLongitudeDirection(){return LongitudeDirection;}
Compass getLatitudeDirection(){return LatitudeDirection;}
};


//------------------------------
//   DO NOT MODIFY TEST CASES
//------------------------------

TEST_CASE( "GPS" ) {
    SECTION( "t1" ) {
        GPS c;
        REQUIRE( c.getLatitude() == 0.0 );
        REQUIRE( c.getLatitudeDirection() == Compass::N );
        REQUIRE( c.getLongitude() == 0.0 );
        REQUIRE( c.getLongitudeDirection() == Compass::W );
    }
    SECTION( "t2" ) {
        GPS c{12.12, 50.34};
        REQUIRE( c.getLatitude() == 12.12 );
        REQUIRE( c.getLatitudeDirection() == Compass::N );
        REQUIRE( c.getLongitude() == 50.34 );
        REQUIRE( c.getLongitudeDirection() == Compass::W );
    }
    SECTION( "t3" ) {
        GPS c{12.12, Compass::S, 50.34, Compass::E};
        REQUIRE( c.getLatitude() == 12.12 );
        REQUIRE( c.getLatitudeDirection() == Compass::S );
        REQUIRE( c.getLongitude() == 50.34 );
        REQUIRE( c.getLongitudeDirection() == Compass::E );
    }
    SECTION( "t4" ) {
        GPS c{122.12, 50.34};
        REQUIRE( c.getLatitude() == 0.0 );
        REQUIRE( c.getLongitude() == 50.34 );
    }
    SECTION( "t5" ) {
        GPS c{122.12, 500.34};
        REQUIRE( c.getLatitude() == 0.0 );
        REQUIRE( c.getLongitude() == 0.0 );
    }
    SECTION( "t6" ) {
        GPS c{-122.12, 50.34};
        REQUIRE( c.getLatitude() == 0.0 );
        REQUIRE( c.getLongitude() == 50.34 );
    }
    SECTION( "t7" ) {
        GPS c{12.12, -50.34};
        REQUIRE( c.getLatitude() == 12.12 );
        REQUIRE( c.getLongitude() == 0.0 );
    }
    SECTION( "t8" ) {
        GPS c{12.12, Compass::W, 50.34, Compass::E};
        REQUIRE( c.getLatitude() == 12.12 );
        REQUIRE( c.getLatitudeDirection() == Compass::N );
        REQUIRE( c.getLongitude() == 50.34 );
        REQUIRE( c.getLongitudeDirection() == Compass::E );
    }
    SECTION( "t9" ) {
        GPS c{12.12, Compass::N, 50.34, Compass::N};
        REQUIRE( c.getLatitude() == 12.12 );
        REQUIRE( c.getLatitudeDirection() == Compass::N );
        REQUIRE( c.getLongitude() == 50.34 );
        REQUIRE( c.getLongitudeDirection() == Compass::W );
    }
    SECTION( "t10" ) {
        GPS c{-12.12, Compass::E, 540.34, Compass::N};
        REQUIRE( c.getLatitude() == 0.0 );
        REQUIRE( c.getLatitudeDirection() == Compass::N );
        REQUIRE( c.getLongitude() == 0.0 );
        REQUIRE( c.getLongitudeDirection() == Compass::W );
    }
}
//------------------------------

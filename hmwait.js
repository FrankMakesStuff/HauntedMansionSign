<<<<<<< HEAD
// include the Themeparks library
var Themeparks = require("themeparks");

// access a specific park
var disneyMagicKingdom = new Themeparks.Parks.WaltDisneyWorldMagicKingdom();

// access wait times via callback
disneyMagicKingdom.GetWaitTimes(function(err, rides) {
	if (err) return console.error(err);

	// Search for HM, once found, output the current wait time
    	for(var i=0, ride; ride=rides[i++];) {
	if( ride.name == "Haunted Mansion" )
        	console.log(ride.waitTime);
    }
=======
// include the Themeparks library
var Themeparks = require("themeparks");

// access a specific park
var disneyMagicKingdom = new Themeparks.Parks.WaltDisneyWorldMagicKingdom();

// access wait times via callback
disneyMagicKingdom.GetWaitTimes(function(err, rides) {
	if (err) return console.error(err);

	// Search for HM, once found, output the current wait time
    	for(var i=0, ride; ride=rides[i++];) {
	if( ride.name == "Haunted Mansion" )
        	console.log(ride.waitTime);
    }
>>>>>>> 70437755a8b59ef5d1e050f19d45bd515eb1c222
});
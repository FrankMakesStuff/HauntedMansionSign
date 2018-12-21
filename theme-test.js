<<<<<<< HEAD
// include the Themeparks library
var Themeparks = require("themeparks");

// access a specific park
var disneyMagicKingdom = new Themeparks.Parks.WaltDisneyWorldMagicKingdom();

// access wait times by Promise
disneyMagicKingdom.GetWaitTimes().then(function(rides) {
    // print each wait time
    for(var i=0, ride; ride=rides[i++];) {
        console.log(ride.name + ": " + ride.waitTime + " minutes wait");
    }
=======
// include the Themeparks library
var Themeparks = require("themeparks");

// access a specific park
var disneyMagicKingdom = new Themeparks.Parks.WaltDisneyWorldMagicKingdom();

// access wait times by Promise
disneyMagicKingdom.GetWaitTimes().then(function(rides) {
    // print each wait time
    for(var i=0, ride; ride=rides[i++];) {
        console.log(ride.name + ": " + ride.waitTime + " minutes wait");
    }
>>>>>>> 70437755a8b59ef5d1e050f19d45bd515eb1c222
}, console.error);
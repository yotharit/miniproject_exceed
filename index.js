var lightMStatus = 0;
var doorMStatus = 0;
var airMStatus = 0;

$(document).ready(function() {
  var link = "http://158.108.165.223/data/5910500147/"

  //Control the AC Manually
  $('#textAir').val("AC is Close");

  $('#airButton').click(function() {
    if(airMStatus === 0){
      airMStatus++;
      $.ajax({
        url: link + "airm/set/on"
      }).done(function() {
        console.log("SUCCESS");
        console.log(airMStatus);
        $('#textAir').val("AC IS OPEN!");
      }).fail(function() {
        console.log("FAIL");
      });
    }
    else {
      airMStatus--;
      $.ajax({
        url: link + "airm/set/off"
      }).done(function(data) {
        console.log("SUCCESS");
        console.log(doorMStatus);
        $('#textAir').val("AC IS CLOSE!");
      }).fail(function() {
        console.log("FAIL");
      });
    }
  }
  );

  //Control the Door Manually
  $('#textDoor').val("DOOR is Close");

  $('#doorButton').click(function() {
    if(doorMStatus === 0){
      doorMStatus++;
      $.ajax({
        url: link + "doorm/set/on"
      }).done(function() {
        console.log("SUCCESS");
        console.log(doorMStatus);
        $('#textDoor').val("DOOR IS OPEN!");
      }).fail(function() {
        console.log("FAIL");
      });
    }
    else {
      doorMStatus--;
      $.ajax({
        url: link + "doorm/set/off"
      }).done(function(data) {
        console.log("SUCCESS");
        console.log(doorMStatus);
        $('#textDoor').val("DOOR IS CLOSE!");
      }).fail(function() {
        console.log("FAIL");
      });
    }
  }
  );

  //Control the FrontDoor Light Manually!
  $('#textLight').val("FRONT LIGHT IS CLOSE!");

  $('#flightButton').click(function() {
    if(lightMStatus === 0){
      lightMStatus++;
      $.ajax({
        url: link + "lightm/set/on"
      }).done(function() {
        console.log("SUCCESS");
        console.log(lightMStatus);
        $('#textLight').val("FRONT LIGHT IS OPEN!");
      }).fail(function() {
        console.log("FAIL");
      });
    }
    else {
      lightMStatus--;
      $.ajax({
        url: link + "lightm/set/off"
      }).done(function(data) {
        console.log("SUCCESS");
        console.log(lightMStatus);
        $('#textLight').val("FRONT LIGHT IS CLOSE!");
      }).fail(function() {
        console.log("FAIL");
      });
    }
  }
  );

  //CHECK FOR STATUS
  setInterval(function() {
    $.ajax({
      url: link + "light"
    }).done(function() {
      console.log("SUCCESS");
    }).fail(function() {
      console.log("FAIL");
    });

  }, 2000);


});

var lightMStatus = 0;
$(document).ready(function() {
  var link = "http://158.108.165.223/data/5910500147/"

  // $.ajax({
  //   url: link + "light"
  // }).done(function(data) {
  //   console.log(data);
  // }).fail(function() {
  //   console.log("FAIL");
  // });

  // $.ajax({
  //   url: link + "light/set/1"
  // }).done(function() {
  //   console.log("SUCCESS");
  // }).fail(function() {
  //   console.log("FAIL");
  // });

  //LIGHT URL

  if(lightMStatus === 0){
    $('#textLight').val("FRONT LIGHT IS CLOSE!");
  }

  //Control the Door!
  $('#flightButton').click(function() {
    $.ajax({
      url: link + "frontLight/set/1"
    }).done(function() {
      console.log("SUCCESS");
      $('#textLight').val("FRONT LIGHT IS OPEN!");
    }).fail(function() {
      console.log("FAIL");
    })
  });



  // setInterval(function() {
  //   $.ajax({
  //     url: link + "frontLight"
  //   }).done(function() {
  //     console.log("SUCCESS");
  //   }).fail(function() {
  //     console.log("FAIL");
  //   });
  // }, 2000);


});

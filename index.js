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
  var lightM = mainURL + "lightM"

  //Control the Door!
  $('#doorButton').click(function() {
    $.ajax({
      url: link //ต้องเพิ่ม
    }).done(function() {
      console.log("SUCCESS");
    }).fail(function() {
      console.log("FAIL");
    })
  });



  setInterval(function() {
    $.ajax({
      url: lightM
    }).done(function() {
      console.log("SUCCESS");
    }).fail(function() {
      console.log("FAIL");
    });
  }, 2000);


});

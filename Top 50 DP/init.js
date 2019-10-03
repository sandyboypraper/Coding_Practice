$('.processing').hide();
$('.test_processing').hide();
$('.upload_testdata').hide();
$('.typing-loader').hide();

function transpose(a) {
    return Object.keys(a[0]).map(function(c) {
        return a.map(function(r) { return r[c]; });
    });
}
var user_id = '';
var DEFAULT_BOT_ID = '4';
var bot_id = '4';
var bot_name = 'hr-bot';
var BOT_NAME = 'hr-bot';
var BOT_DISPLAY_NAME = 'hello world';
var API_SERVER_URL = "/chat/query/";
var CLEAR_API_URL = "/chat/clear_user_data/";
var STATIC_IMG_PATH = "/static/EasyChatApp/img";
var STATIC_MP3_PATH = "/static/EasyChatApp/mp3";
var MESSAGE_IMG = "/static/EasyChatApp/img/favicon.png";
var BOT_THEME_COLOR = '1a237e';
var timer_var = ''
var isMapJsLoaded = 0
var mapId = 1
var BookingID = "";
var RoomID = "";
var CustomerID = "";

function getUrlVars() {
    var vars = {};
    var parts = window.location.href.replace(/[?&]+([^=&]+)=([^&]*)/gi, function(m,key,value) {
        vars[key] = value;
    });
    return vars;
}

function getBotID(){
    bot_id = getUrlVars()["id"];
    if(bot_id==undefined || bot_id==null || bot_id=="" || bot_id=="undefined" || bot_id=="null"){
        bot_id=DEFAULT_BOT_ID;
    }
    return bot_id;
}

function getBotName(){
    bot_name = getUrlVars()["name"];
    if(bot_name==undefined || bot_name==null || bot_name=="" || bot_name=="undefined" || bot_name=="null"){
        bot_name=BOT_NAME;
    }
    return bot_name;
}


$(document).on("click","#scrollBot-img", function(e){
    $("#style-2").stop().animate({ scrollTop: $("#style-2")[0].scrollHeight}, 500);
});

$("#style-2").scroll(function() {
   if($("#style-2")[0].scrollHeight-($('#style-2').scrollTop()+$('#style-2').height()) > 100){
       $("#scrollBot-img").show(); //reached the desired point -- show div
   }else{
       $("#scrollBot-img").hide(); //reached the desired point -- show div    
   }
});

function is_mobile(){
    if( /Android|webOS|iPhone|iPad|iPod|BlackBerry/i.test(navigator.userAgent) ) {
        return true;
    } else {
        return false;
    }
}


function get_config_params()
{
    // $("#chatbot-preloader").show();
    $.ajax({
        url: "/chat/get_config_params/",
        type: "POST",
        data: {
        },
        success: function(response) {
            site_title = response['site_title'];
            $('.site-title').html(site_title);
        },
        error: function(xhr, textstatus, errorthrown) {
            // console.log("Please report this error: "+errorthrown+xhr.status+xhr.responseText);
        }
    });

    bot_id = getBotID();
    bot_name = getBotName();
    // $("#chatbot-preloader").show();
    $("#global-preloader").show();
    $("#chatbot-main-div").hide();

    $.ajax({
       url: "/chat/get-bot-message-image/",
       type: "POST",
       data: {
           bot_id: bot_id,
       },
       success: function(response) {
           if(response["status"]==200)
           {
              if(response['bot_message_image_url']!=null
                &&response['bot_message_image_url']!='{"items":[]}'&& response['bot_message_image_url']!=""){
                 MESSAGE_IMG = response['bot_message_image_url']
              }
              BOT_THEME_COLOR = response['bot_theme_color'];
              if(response['bot_display_name']!=''){
                BOT_DISPLAY_NAME = response['bot_display_name'];
              }
              $("#chatbot_name_id").html('Ask '+BOT_DISPLAY_NAME+' for Help')
              $("#restart-button").css('background','#'+BOT_THEME_COLOR);
              $("#header").css("background-color",'#'+response['bot_theme_color']);
              $("#submit-img").css("color",'#'+response['bot_theme_color']+' !important');
              $("#submit").css("color",'#'+response['bot_theme_color']);
              $("#voice_btn").css('color','#'+BOT_THEME_COLOR);

              $("#start_button").css('background-color','#'+BOT_THEME_COLOR);
           }else{
               $("#header").css("background-color",'#'+BOT_THEME_COLOR+'!important');
               $("#restart-button").css('background','#'+BOT_THEME_COLOR);
               $("#submit-img").css('color','#'+BOT_THEME_COLOR);
           }

           $("#global-preloader").hide();
           // $("#chatbot-preloader").hide();
           $("#chatbot-main-div").show();
       },
       error: function(xhr, textstatus, errorthrown) {
       }
   });
}

get_config_params();

var scroll_to_bottom = function() {
  $('#style-2').scrollTop($('#style-2')[0].scrollHeight);
};

function returnTime() {
    var d = new Date();
    var hours = d.getHours().toString();
    var minutes = d.getMinutes().toString();
    var flagg = "AM";
    if(parseInt(hours) > 12){
        hours = hours - 12;
        flagg = "PM";
    }
    if(hours.length==1){
        hours = "0"+hours;
    }
    if(minutes.length==1){
        minutes = "0"+minutes;
    }

    var time = hours+":"+minutes+" "+flagg;
    return time;
}


function appendResponseServer(sentence, flag, url1, url2, tooltip_response){
    sentence = sentence.replace("<p>","");sentence = sentence.replace("</p>","");
    sentence = sentence.replace("<strong>","<b>");sentence = sentence.replace("</strong>","</b>");
    sentence = sentence.replace("<em>","<i>");sentence = sentence.replace("</em>","</i>");
    sentence = sentence.replace('background-color:#ffffff; color:#000000','');
    sentence = sentence.replace("background-color:#ffffff;","");
    var html = ""
    if(tooltip_response==""||tooltip_response=="undefined"){
        html =
        `<div class="row chatmessage">\
            <div class="col s1 l1" >\
               <img src="`+MESSAGE_IMG+`" width=34 class="chatbot_left_image">\
            </div>\
            <div class="col s10 m10">\
               <div class="chip chip2 chip_left" >\
                  <span>`+sentence+`</span>\
               </div>\
            </div>\
            <div class="timestampl" >`+returnTime()+`</div>\
        </div>`;
    }else{
      html =
      `<script>
       $(document).ready(function(){
        $('.tooltipped').tooltip();
      });
      </script>
      <div class="row chatmessage">\
          <div class="col s1 l1" >\
             <img src="`+MESSAGE_IMG+`" width=34 class="chatbot_left_image">\
          </div>\
          <div class="col s10 m10">\
             <div class="chip chip2 chip_left" >\
                <span>`+sentence+`</span>\
                <p align="right" style="margin: 0em;padding: 0em;"><i class="material-icons prefix blue-text tooltipped" data-position="bottom" data-tooltip="`+tooltip_response+`">info</i></p>\
             </div>\
          </div>\
          <div class="timestampl" >`+returnTime()+`</div>\
      </div>`;
    }

    $("#style-2").append(html);
}

function appendButtons(display_list, value_list){
    var string = '';
    for(var i=0;i<value_list.length;i++){
        string+=`
            <style>
                 .button3:hover {
                     color: white!important;
                     background-color:#`+BOT_THEME_COLOR+`;
                 }

                 .button2{
                    border: 1px solid #`+BOT_THEME_COLOR+`;
                 }
            </style>`;

        string += '<button class="button2 button3 chipbutton" style="color: #'+BOT_THEME_COLOR+'" value="'+value_list[i]+'">';
        string += display_list[i];
        string += '</button>';
    }
    var html = '\
    <div class="row chatmessage">\
        <div class="col s2 l2">\
        </div>\
        <div class="col s10 l10">\
           <div>'+
              string
           +'</div>\
        </div>\
    </div>\
    ';
    $("#style-2").append(html);
}


function appendVideo(video_url_list){

    if(video_url_list.length==0){
        return;
    }

    var video_html = "";

    if(video_url_list[0].indexOf("embed")!=-1){
        var video_html = `
        <div class="video-container">
            <iframe height="250em" src="`+video_url_list[0]+`" frameborder="1" allowfullscreen></iframe>
        </div>`;
    }else{
        var video_html = `
        <video width="320" height="240" controls>
          <source src="`+video_url_list[0]+`" type="video/mp4">
        </video>`;
    }

    var html = `
    <div class="row chatmessage" style="margin-left: 4em;">
        <div class="col s11">`+video_html+`</div>
        <div class="col s1"></div>
    </div><br>`;

    $("#style-2").append(html);
}

function appendImage(image_url_list){

    if(image_url_list.length==0)
    {
        return;
    }

    var html = `<div class="col s11">  <!-- <div class="slider">
            <ul class="slides"> -->`

    for(var i=0;i<image_url_list.length;i++)
    {
        if(i==1){
          break;
        }

        html += `
             <!-- <li> -->
                <img class="materialboxed responsive-img" src="`+image_url_list[i]+`" onclick="openImageInTab(this.src)">
              <!-- </li> -->`
    }

    html +=`<!--</ul>
        </div>--> </div>`

    var image_html = `
    <div class="row chatmessage" style="margin-left: 2em;">
        `+html+`
    </div><br>`

    $("#style-2").append(image_html);

    $(document).ready(function(){
        $('.slider').slider({
            indicators:true,
            height:200,
            interval:3000,
            full_width: true
        });
    });

    $(document).ready(function(){
        $('.materialboxed').materialbox();
    });
}

function openImageInTab(src){
   window.open(src);
}

function slider_size() {
    $('#chat_slider').css("width", "199.149px");
}

function updateSlider(slideAmount) {
    // console.log("Here it is ");
    $("thumb").css("style", "left: 162.24px; height: 0px; width: 0px; top: 10px; margin-left: 7px;");
    var sliderDiv = document.getElementById("sliderAmount");
    $('#query').val(slideAmount);
    $("#submit-img").attr('src',STATIC_IMG_PATH+'/send2.png');
}


function appendSlider(min_val, max_val, step_val, placeholder, element_id){

   var html = `
    <div class="row chatmessage chat_slider_chatmessage">
      <div class="col s1"></div>
      <div class="col s11"><p><b>`+placeholder+`</b></p></div>
      <div class="col s1"></div>
      <div class="col s2">
          <br>`+min_val+`
      </div>
      <div class="col s7">
      <form action="#">
        <p class="range-field">
          <input type="range" class="chat_slider" id="`+element_id+`" min="`+min_val+`" max="`+max_val+`" step="`+step_val+`" onclick="slider_size()" onchange="updateSlider(this.value)"/>
        </p>
      </form>
      </div>
      <div class="col s2">
      <br>`+max_val+`
      </div>
    </div>
    `
    $("#style-2").append(html);
    slider_size();
    putSliderValueIntoQuery();
}

function putSliderValueIntoQuery(){
   chat_slider_element = document.getElementsByClassName("chat_slider");
   var message = "";
   for(var i=0;i<chat_slider_element.length;i++){
      message += $("#"+chat_slider_element[i].id).val();
      if(i!=chat_slider_element.length-1){
         message+=", "
      }
   }
   $("#query").val(message);
   $('#query').keyup();
}


function updateDate(date) {

    $('#query').val(date);
    $("#submit-img").attr('src',STATIC_IMG_PATH+'/send2.png');
}

function appendDate() {

   var html = `
    <div class="row chatmessage" style="margin-left: 4em;">
  <div class="col s8">
    <input type="date" onchange="updateDate(this.value)">
  </div>
    `
    $("#style-2").append(html);
}


function updateDropdown(value) {

    $('#query').val(value);
    $("#submit-img").attr('src',STATIC_IMG_PATH+'/send2.png');
}

function appendDropdown(display_list, value_list) {

    // console.log("List: ", value_list, display_list);

    var html = `
    <div class="row chatmessage" style="margin-left: 4em;">
    <div class="input-field col s8">
        <select class="select_class" onchange="updateDropdown(this.value)">
          <option value="" disabled selected>Choose your option</option>
          `
    for(var i=0;i<value_list.length;i++)
    {
        html += `<option value="`+value_list[i]+`">`+display_list[i]+`</option>`
    }

    html += `</select>
    </div>
    `
    $("#style-2").append(html);
    $('select').material_select();
}

function appendCard(card_details){

    card_title_list = []
    card_img_url_list = []
    card_url_list = []
    card_content_list = []

    for(i=0;i<card_details.length;i++){
        title = card_details[i]["title"]
        img_url = card_details[i]["img_url"]
        url = card_details[i]["link"]
        content = card_details[i]["content"]

        card_title_list.push(title);
        card_img_url_list.push(img_url);
        card_url_list.push(url);
        card_content_list.push(content);
    }

    var html = `
    <div class="row chatmessage" style="margin-left: 4em;">
        <div class="col s8">
            <div class="card">
                <div class="card-image waves-effect waves-block waves-light">
                    <img class="activator responsive-image" src="`+card_img_url_list[0]+`">
                </div>
                <div class="card-content" style="border: black;">
                    <span class="card-title activator grey-text text-darken-4" style="font-size:15px;">`+card_title_list[0]+`<i class="material-icons right">more_vert</i></span>
                    <p>
                        <a href="`+card_url_list[0]+`" target="_blank">Please click here</a>
                    </p>
                </div>
                <div class="card-reveal">
                    <span class="card-title grey-text text-darken-4" style="font-size:15px;">`+card_title_list[0]+`<i class="material-icons right">close</i></span>
                    <p style="font-size:15px;">`+card_content_list[0]+`</p>
                </div>
            </div>
        </div>
    </div><br>`;

  $("#style-2").append(html);
}


function appendResponseUser(sentence){
    sentence = sentence.replace("<p>","");sentence = sentence.replace("</p>","");
    sentence = sentence.replace("<","#");sentence = sentence.replace(">","#");

    var html =
    `<script>
     $(document).ready(function(){
      $('.tooltipped').tooltip();
    });
    </script>

    <div class="row chatmessage">\
        <div class="col s3">\
        </div>\
        <div class="col s9">\
            <div class="chip chip2 right user_msg chip_right" style="background-color: #`+BOT_THEME_COLOR+`">\
                <span>`+sentence+`</span>\
            </div>\
        </div>\
        <div class="timestampr" >`+returnTime()+`</div>\
    </div>`;
    $("#style-2").append(html);
    scroll_to_bottom();
    clearTimeout(timer_var)
}

function appendRecommendationsList(list){
    if(list.length > 0){
        var html =
        '<div class="row chatmessage">\
            <div class="col s2">\
            </div>\
            <div class="col s9 l9">\
               <div class="button-group button-group2" style="margin-top:4px;">\
               ';

        for(var i=0;i<list.length;i++){
            html += '<div class="button recommendation_style chiprecommendation" style="color: #'+BOT_THEME_COLOR+'">'+list[i]+'</div>';
        }

        html += '</div></div></div>';
        $("#style-2").append(html);
    }
}

function appendGoogleSearchResultsList(google_search_results){
    //console.log(discrptnlist)
    if(google_search_results.length > 0){
        var html =
        `<div class="row chatmessage">\
                <div class="google_search_cards">
               `;

        for(var i=0;i<google_search_results.length;i++){
            html += `<div value="`+google_search_results[i]["google_search_link"]+`" 
            class="google_search_card chipgoogleresult">
            <p class="google_search_title">`+google_search_results[i]["google_search_title"]+`<p><p class="google_search_link" style="margin-bottom:1em">
            `+google_search_results[i]["google_search_link"]+`<p><hr><p class="google_search_description">`+google_search_results[i]["google_search_descrptn"]+`</p></div>`;
        }

        html += '</div></div>';
        $("#style-2").append(html);
    }
  var elements = document.getElementsByClassName("google_search_description");
  for(var i=0; i<elements.length; i++) {
      limitLinesOfGoogleSearchResult(elements[i], 2);
  }
  var elements = document.getElementsByClassName("google_search_title");
  for(var i=0; i<elements.length; i++) {
      limitLinesOfGoogleSearchResult(elements[i], 2);
  }
  var elements = document.getElementsByClassName("google_search_link");
  for(var i=0; i<elements.length; i++) {
      limitLinesOfGoogleSearchResult(elements[i], 1);
  }
  if(is_mobile()){
    var elements = document.getElementsByClassName("google_search_cards");
    elements[elements.length-1].classList.add("hide_scrollbar");
    }
}

function limitLinesOfGoogleSearchResult(el, nLines) {
  j=0;
  while(j<2){
  var nHeight,
    el2 = el.cloneNode(true);
  el2.style.position = 'absolute';
  el2.style.top = '0';
  el2.style.width = '10%';
  el2.style.overflow = 'hidden';
  el2.style.visibility = 'hidden';
  el2.style.whiteSpace = 'nowrap';
  el.parentNode.appendChild(el2);
  nHeight = (el2.clientHeight+2)*nLines; 
  el.parentNode.removeChild(el2);
  el2 = null;
  if (el.clientHeight > nHeight) {
    var i = 0,
      imax = nLines * 35;
    while (el.clientHeight > nHeight) {
      el.innerHTML = el.textContent.slice(0, -2) + '&hellip;';
      ++i;
      if (i === imax) break;
    }
  }
  j=j+1
}
}


$(document).ready(function() {
    document.cookie = Math.random();
    if(is_mobile()){
    }else{
        $("#query").focus();
    }
    $("#navig").css("background-color","#FFF");
    $("#submit-img").attr('src',STATIC_IMG_PATH+'/send1.png');
});

function enableInput(query){
    $("#query").removeAttr('disabled');
    $("#query").attr("placeholder","Please type your query here.");
}

function disableInput(){
    $('#query').val("");
    $('#query').attr('placeholder','Please select an option from the above choices');
    $("#query").attr('disabled','disabled');
}

$(document).on("keyup","#query",function (e) {
    var key = e.which;
    if(key == 13)
    {
        $('#submit-img').click();
        return false;
    }
});

function appendGoogleMap() {
  current_latitude = ""
  current_longitude = ""
  if (("geolocation" in navigator)) {
    // check if geolocation is supported/enabled on current browser
    navigator.geolocation.getCurrentPosition(
     function success(position) {
       // for when getting location is a success
       console.log('latitude', position.coords.latitude,
                   'longitude', position.coords.longitude);
        current_latitude = position.coords.latitude
        current_longitude = position.coords.longitude
     },
    function error(error_message) {
      // for when getting location results in an error
      console.error('An error has occured while retrieving' +
                    'location before', error_message)
      // alert("error has occured before")
      // alert(error_message)
      ajaxCallToIndex("Share Pincode", API_SERVER_URL)
      return;
    });
  } else {
    // alert("geolocation is not supported before")
    // geolocation is not supported
    // get your location some other way
    console.log('geolocation is not enabled on this browser')
    ajaxCallToIndex("Share Pincode", API_SERVER_URL)
    return;
  }

  $("#map").empty();

  html = `
      <style>
        #map`+mapId+` {
          height: 100%;
        }
        html, body {
          height: 100%;
          margin: 0;
          padding: 0;
        }
      </style>
      <div id="map`+mapId+`"></div>

      <script>

      var lat_coord = ""
      var lng_coord = ""
      var map;
      var setMarker = false; ////Has the user plotted their location marker?
      var marker = ""

      var myLatlng = ""
      if (("geolocation" in navigator)) {
        // check if geolocation is supported/enabled on current browser
        navigator.geolocation.getCurrentPosition(
         function success(position) {
           // for when getting location is a success
           console.log('latitude', position.coords.latitude,
                       'longitude', position.coords.longitude);
           // getAddress(position.coords.latitude,
           //            position.coords.longitude)
         lat_coord = position.coords.latitude
         lng_coord = position.coords.longitude
         var pos = {
              lat: position.coords.latitude,
              lng: position.coords.longitude
            };

            if(setMarker==true){
              console.log("set marker is true")
              console.log("postition is ",pos)
               map.setCenter(pos);
               marker.setPosition(map.getCenter());

            }else{
            }


         // alert(lat_coord)
         // alert(lng_coord)
         },
        function error(error_message) {
          // for when getting location results in an error
          console.error('An error has occured while retrieving' +
                        'location', error_message)
          // alert("error has occured")
          // alert(error_message)
        });
      } else {
        console.log('geolocation is not enabled on this browser')
      }



        function initMap() {
          // var myLatlng = new google.maps.LatLng(19.108290,72.878370);
          var myLatlng = new google.maps.LatLng(lat_coord,lng_coord);
          map = new google.maps.Map(document.getElementById('map`+mapId+`'), {
            center: myLatlng,
            zoom: 15
          });
          console.log("position coordinate ",myLatlng)
          var centerControlDiv = document.createElement('div');
          var centerControl = new CenterControl(centerControlDiv, map);

          centerControlDiv.index = 1;
          map.controls[google.maps.ControlPosition.BOTTOM_CENTER].push(centerControlDiv);


          if(setMarker==false){
            marker = new google.maps.Marker({
              position: myLatlng,
              map: map,
              draggable:true,
              title:"Drag me!"
          });
            setMarker=true;
            map.addListener('drag', function(e) {
              // placeMarkerAndPanTo(e.latLng, map);
              placeMarkerAndPanTo(map.getCenter(), map);
            });
            console.log("set marker is false")
          }else{
           marker.setPosition(map.getCenter());
          console.log("set marker is true")
          }
      }

      function placeMarkerAndPanTo(latLng, map) {
           marker.setPosition(map.getCenter());
           console.log('set position', latLng)
      }

      function CenterControl(controlDiv, map) {

          // Set CSS for the control border.
          var controlUI = document.createElement('div');
          controlUI.style.backgroundColor = '#fff';
          controlUI.style.border = '2px solid #fff';
          controlUI.style.borderRadius = '3px';
          controlUI.style.boxShadow = '0 2px 6px rgba(0,0,0,.3)';
          controlUI.style.cursor = 'pointer';
          controlUI.style.marginBottom = '22px';
          controlUI.style.textAlign = 'center';
          controlUI.title = 'Click to Submit the location';
          controlDiv.appendChild(controlUI);

          // Set CSS for the control interior.
          var controlText = document.createElement('div');
          controlText.style.color = 'rgb(25,25,25)';
          controlText.style.fontFamily = 'Roboto,Arial,sans-serif';
          controlText.style.fontSize = '16px';
          controlText.style.lineHeight = '38px';
          controlText.style.paddingLeft = '5px';
          controlText.style.paddingRight = '5px';
          controlText.innerHTML = 'Submit your location';
          controlUI.appendChild(controlText);

          // Setup the click event listeners: simply set the map to Chicago.
          controlUI.addEventListener('click', function() {
            var lat = marker.getPosition().lat();
            var lng = marker.getPosition().lng();
            console.log("lat lng  is ",lat+"__"+lng)
            console.log("button clicked")
            $("#map`+mapId+`").hide()
            ajaxCallToIndex(lat+"__"+lng,API_SERVER_URL)
          });

        }
      </script>`;

      if(isMapJsLoaded==0){
        html+=`<script src="https://maps.googleapis.com/maps/api/js?key=AIzaSyBAHTtk1lkVvIl1X_i7_1aIK9RCrhqGEpQ&callback=initMap" defer></script>`;
      }
      mapId+=1;
      $("#style-2").append(html);
}

var is_flow_ended=true;
function appendServerChat(data) {
    var sentence = "";
    var tooltip_response = "";
    if(data['status_code']=="200"){
        sentence = data['response']['text_response']['text'];
        if(data['response']['tooltip_response']){
          tooltip_response = data['response']['tooltip_response']
        }else{
          tooltip_response = "";
        }
    }else{
        sentence = data['status_message'];
        tooltip_response = "";
    }

    appendResponseServer(sentence, false, "", "", tooltip_response);

    choices = [];
    if("choices" in data["response"]){
      choices = data['response']['choices'];      
    }

    cards = [];
    if("cards" in data["response"]){
      cards = data["response"]["cards"];      
    }

    images = [];
    if("images" in data["response"]){
      images = data["response"]["images"];      
    }

    videos = [];
    if("videos" in data["response"]){
      videos = data["response"]["videos"];      
    }

    display_list = []
    value_list = []
    for(i=0;i<choices.length;i++){
        display_list.push(choices[i]["display"]);
        value_list.push(choices[i]["value"]);
    }

    if(data["response"]["text_response"]["modes"]["is_button"]=="true") {
        appendButtons(display_list, value_list);
    }

    is_flow_ended = data["response"]["is_flow_ended"];

    if(data['response']["text_response"]["modes"]['is_slidable']=="true") {

        list_of_sliders = data['response']['text_response']["modes_param"]["is_slidable"];

        for(var i=0;i<list_of_sliders.length;i++){
           var slider_min = data['response']['text_response']["modes_param"]["is_slidable"][i]["min"];
           var slider_max = data['response']['text_response']["modes_param"]["is_slidable"][i]["max"];
           var slider_step = data['response']['text_response']["modes_param"]["is_slidable"][i]["step"];
           var placeholder = data['response']['text_response']["modes_param"]["is_slidable"][i]["placeholder"];
           appendSlider(slider_min, slider_max, slider_step, placeholder, "chat_min_max_slider_"+i);
        }
    }
    if(data['response']["text_response"]["modes"]['is_date']=="true") {
        appendDate();
    }

    if(data['response']["text_response"]["modes"]['is_dropdown']=="true") {
        appendDropdown(display_list, value_list);
    }

    //month
    if(data['response']["text_response"]["modes_param"]['ask_month']=="true")
    {
      
      year = data['response']["text_response"]["modes_param"]['year'];
      appendAskMonth(year);
      // ajaxCallToIndex("may", API_SERVER_URL);
      // console.log("heyboii");
    }


    if(data['response']["recommendations"].length!=0){
        appendRecommendationsList(data["response"]["recommendations"]);
    }

    if(data['response']["text_response"]["modes_param"]['isFormLogin'])
    {
      showForm();
    }


    //for ticket raise
    if(data['response']["text_response"]["modes_param"]['is_checkbox'])
    {
      appendTicketCatagoryList(data['response']["text_response"]["modes_param"]['is_checkbox'] , data['response']["text_response"]["modes_param"]['Cat'] ,data['response']["text_response"]["modes_param"]['SubCat']);
      BookingID = data['response']["text_response"]["modes_param"]['BookingID'];
      RoomID = data['response']["text_response"]["modes_param"]['RoomID'];
      CustomerID = data['response']["text_response"]["modes_param"]["CustomerID"];
    }

    //for ticket status
    if(data['response']["text_response"]["modes_param"]['is_ticket_status'])
    {
      var ticket_status_list = data['response']["text_response"]["modes_param"]['status_list'];
      extract_status_list_string(ticket_status_list);
    }

// console.log(data['response']["text_response"]["modes_param"]['error_msg']);

    if(data['response']["text_response"]["modes_param"]['error_msg'])
    {
      again_Login(data['response']["text_response"]["modes_param"]['error_msg']);
    }

    if(data['response']["text_response"]["modes"]['is_invoice'] && data['response']["text_response"]["modes_param"]['dont_show_invoice'] != "true")
    {
      console.log(data['response']["text_response"]["modes_param"]['invoice_list']);
      append_invoice_table(data['response']["text_response"]["modes_param"]['invoice_list']);
    }

    if(data['response']["google_search_results"].length!=0){
        appendGoogleSearchResultsList(data["response"]["google_search_results"]);
    }
    
    is_typable = data['response']['text_response']['modes']['is_typable'];

    is_location_required = data['response']['text_response']['modes']['is_location_required'];

    if(cards.length!=0){
        appendCard(cards);
    }
    if(is_typable=="false")
        disableInput();
    else
        enableInput();

    if(videos.length!=0){
       appendVideo(videos);
    }

    if(images.length!=0 && videos.length==0){
      appendImage(images);
    }

    if(is_location_required){
        appendGoogleMap();
    }
}

function playSound(filename){
    var mp3Source = '<source src="' + filename + '" type="audio/mpeg">';
    document.getElementById("sound").innerHTML='<audio autoplay="autoplay">' + mp3Source + '</audio>';
}

function ajaxCallToIndex(sentence, url , is_List_Response = false){

    $("#style-2").append(`<div class="typing-loader"></div>`);
    $(".typing-loader").show();
    scroll_to_bottom();

    $.ajax({
        url: url,
        type: "POST",
        data: {
            message: sentence,
            user_id: user_id,
            bot_id: bot_id,
            bot_name: bot_name,
            bot_display_name: BOT_DISPLAY_NAME,
            channel: "Web",
            channel_params: "",
            is_List_Response
        },
        success: function(data){

            if(isSafari){
              $("#start_button").css("display", "none");
              $("#submit-img").css("display", "block");
            }else{
              $("#start_button").css("display", "block");
              $("#submit-img").css("display", "none");
            }

            user_id = data['user_id'];
            bot_id = data['bot_id'];

            if(data['timer_value']){
              timer_var = setTimeout(function(){
                ajaxCallToIndex(data['auto_response'], API_SERVER_URL);
              }, data['timer_value']);
            }

            setTimeout(function(){
                $(".typing-loader").remove();
                appendServerChat(data);
                playSound(STATIC_MP3_PATH+"/popup.mp3");
                document.getElementById('query').value=''
                if(!is_mobile()){
                    $("#query").focus();
                }
                scroll_to_bottom();
            }, 500);
        },
        error: function (jqXHR, exception) {
           appendResponseServer(BOT_DISPLAY_NAME+" bot is under maintenance, Please try again after some time. Sorry for your inconvenience.", false, "", "","");
           scroll_to_bottom();
        },
    });
}


function GetWelcomeResponse(channel, bot_id, bot_name){
    var response = $.ajax({
        url: "/chat/get_channel_details/",
        type: "POST",
        async: false,
        data: {
            channel_name:channel,
            bot_id:bot_id,
            bot_name:bot_name,
        },
        success: function(data){
            // console.log("Success", data);
            return data;
        },
        error: function (jqXHR, exception) {
             appendResponseServer(BOT_DISPLAY_NAME+" bot is under maintenance, Please try again after some time. Sorry for your inconvenience.", false, "", "","");
             scroll_to_bottom();
        },
    }).responseJSON;

    return response;
}

function getWelcomeMessage(bot_id,bot_name)
{
    channel_details = GetWelcomeResponse("Web", bot_id,bot_name);
    message = channel_details["welcome_message"];
    featues_list = channel_details["initial_messages"]["items"];
    setTimeout(function(){
        appendResponseServer(message,"","","","");
        appendRecommendationsList(featues_list);
        playSound(STATIC_MP3_PATH+"/popup.mp3");
        is_restart_allow=true;
    }, 500);
}

if(window.location.pathname=='/chat/index/')
{
    bot_id = getBotID();
    bot_name = getBotName();
    getWelcomeMessage(bot_id,bot_name);
    sentences = get_data(bot_id,bot_name);
    autocomplete(document.getElementById("query"), sentences);
}

$("#submit-img").click(function(){
    if(($.trim($('#query').val()) != '') && ($("#query").val()).length<300){
        var sentence = $("#query").val();
        sentence = $($.parseHTML(sentence)).text();
        if (sentence.length == 0) {      // error!
          $("#query").val("");
          return;
        }
        $("#query").val("");
        disableInput();
        appendResponseUser(sentence);
        ajaxCallToIndex(sentence, API_SERVER_URL);
        $("#submit-img").attr('src',STATIC_IMG_PATH+'/send1.png');
    }
    else{

    }

    if(document.getElementsByClassName("chat_slider").length>0){
       $(".chat_slider_chatmessage").remove();
    }
});

var is_restart_allow = true;

$('body').on('click','#restart-button', function(){
  restart_chatbot();
});

function restart_chatbot() {
  $(".chatmessage").remove();
    clearTimeout(timer_var)
    enableInput("");

    if(!is_restart_allow){
       return;
    }

    is_restart_allow=false;
    $.ajax({
        url: CLEAR_API_URL,
        type: "POST",
        data: {
            user_id: user_id,
        },
        success: function(data){
            $("#query").val("");
            $("#submit-img").attr('src',STATIC_IMG_PATH+'/send1.png');
            bot_id = getBotID();
            bot_name = getBotName()
            getWelcomeMessage(bot_id,bot_name);
        }
    });
}

$('body').on('click','#minimize-chatbot', function(){
  parent.postMessage('close-bot','*')
});



$('body').on('click','#close-chatbot', function(){
  if (user_id=="" || getCookie("isFeedbackDone")=="1") {
    close_chatbot()
  }
  else{
  document.getElementById("style-2").style.opacity="0.3"
  document.getElementById("style-2").style.pointerEvents="none"
  document.getElementById("feedback_box_container").style.display="block"
  document.getElementById("feedback_box_container").style.backgroundColor='#'+BOT_THEME_COLOR
  document.getElementById("submit-feedback").style.backgroundColor='#'+BOT_THEME_COLOR
  }

   // $('#allincall-chat-box', window.parent.document).hide("slow");
   // $('#allincall-popup', window.parent.document).show("slow");
   //parent.postMessage('close-bot','*')
});
$('body').on('click','#submit-feedback', function(){
  setCookie("isFeedbackDone","1");
  rating=document.querySelector('input[name="feedback_star"]:checked').value;
  comments=document.getElementById("comment-box").value
  save_feedback(user_id,rating,comments)
  close_chatbot()
});

$('body').on('click','#close-feedback-form', function(){
  close_feedback_form();
});

$('body').on('click','#no-feedback-given', function(){
  setCookie("isFeedbackDone","1");
  close_chatbot();
});

function setCookie(cookiename,cookievalue) {
  document.cookie = cookiename + "=" + cookievalue;
}

function getCookie(cookiename) {
  var cookie_name = cookiename + "=";
  var decodedCookie = decodeURIComponent(document.cookie);
  var cookie_array = decodedCookie.split(';');
  for(var i = 0; i < cookie_array.length; i++) {
    var c = cookie_array[i];
    while (c.charAt(0) == ' ') {
      c = c.substring(1);
    }
    if (c.indexOf(cookie_name) == 0) {
      return c.substring(cookie_name.length, c.length);
    }
  }
  return "";
}
function close_chatbot(argument) {
  parent.postMessage('close-bot','*')
  close_feedback_form();
  restart_chatbot();
}

function save_feedback(user_id,rating,comments) {
  $.ajax({
      url: "/chat/save_feedback/",
      type: "POST",
      data: {
        user_id:user_id,
        rating:rating,
        comments:comments,
      },
      success: function(response) {
      },
      error: function(xhr, textstatus, errorthrown) {
          // console.log("Please report this error: "+errorthrown+xhr.status+xhr.responseText);
      }
  });
}

function close_feedback_form() {
  document.getElementById("style-2").style.opacity="1"
  document.getElementById("feedback_box_container").style.display="none"
  document.getElementById("style-2").style.pointerEvents="all"
  var ele = document.getElementsByName("feedback_star");
   for(var i=0;i<ele.length;i++){
      ele[i].checked = false;
   }
  document.getElementById("comment-box").value="";
}



$('body').on('click','#logo-container', function(){
    if(!is_mobile()){
        $("#query").focus();
    }
});

$('#query').on('input',function(e){
    var value = $("#query").val();
    if($.trim($('#query').val()) == ''){
        $("#submit-img").attr('src',STATIC_IMG_PATH+'/send1.png');
    }
    else{
        $("#submit-img").show();
        $("#submit-img").attr('src',STATIC_IMG_PATH+'/send2.png');
    }
});


$(document).on('click','.button2', function(){
    $(this).css('background-color', '#'+BOT_THEME_COLOR);
    $(this).css('color', 'white');
    $('.button2').attr('disabled', "");
    $('.button2').attr('class', 'button2 chipbutton');
    var sentence = $(this).html();
    if(sentence.indexOf("thumbs-up-filled")!=-1){
        sentence = "Helpful";
    }else if(sentence.indexOf("thumbs-down-filled")!=-1){
        sentence = "Unhelpful";
    }
    value = $(this).val();
    appendResponseUser(sentence);
    ajaxCallToIndex(value, API_SERVER_URL);
    $("#submit-img").attr('src',STATIC_IMG_PATH+'/send1.png');
});

$(document).on('click','.chiprecommendation', function(){
    $(this).css('background-color', '#'+BOT_THEME_COLOR);
    $(this).css('color', 'white');
    var sentence = $(this).html();
    appendResponseUser(sentence);
    ajaxCallToIndex(sentence, API_SERVER_URL);
    $("#submit-img").attr('src',STATIC_IMG_PATH+'/send1.png');
});

$(document).on('click','.chipgoogleresult', function(){
    // /$(this).css('background-color', '#'+BOT_THEME_COLOR);
    //$(this).css('color', 'white');
    var url_link = $(this).attr("value");
    var win = window.open(url_link, '_blank');
    win.focus();
    //console.log(url_link);
});

function autocomplete(inp, arr) {
  /*the autocomplete function takes two arguments,
  the text field element and an array of possible autocompleted values:*/
  var currentFocus;
  /*execute a function when someone writes in the text field:*/
  inp.addEventListener("input", function(e) {
      var a, b, i, val = this.value;
      /*close any already open lists of autocompleted values*/
      closeAllLists();
      if (!val) { return false;}
      currentFocus = -1;
      /*create a DIV element that will contain the items (values):*/
      a = document.createElement("DIV");
      a.setAttribute("id", this.id + "autocomplete-list");
      a.setAttribute("class", "autocomplete-items");
      /*append the DIV element as a child of the autocomplete container:*/
      this.parentNode.appendChild(a);
      /*for each item in the array...*/
      var max_element_to_show = 0;
      for (i = 0; i < arr.length; i++) {

        if(max_element_to_show>5){
          break;
        }

        if(is_flow_ended){
          /*check if the item starts with the same letters as the text field value:*/
          if (arr[i].toUpperCase().indexOf(val.toUpperCase())!=-1) {
            /*create a DIV element for each matching element:*/
            b = document.createElement("DIV");
            /*make the matching letters bold:*/
            b.innerHTML = "<strong>" + arr[i].substr(0, val.length) + "</strong>";
            b.innerHTML += arr[i].substr(val.length);
            /*insert a input field that will hold the current array item's value:*/
            b.innerHTML += "<input type='hidden' value='" + arr[i] + "'>";
            /*execute a function when someone clicks on the item value (DIV element):*/
                b.addEventListener("click", function(e) {
                /*insert the value for the autocomplete text field:*/
                inp.value = this.getElementsByTagName("input")[0].value;
                /*close the list of autocompleted values,
                (or any other open lists of autocompleted values:*/
                closeAllLists();
                $('#submit-img').click();
            });
            a.appendChild(b);
            max_element_to_show+=1;
          }          
        }
      }
  });
  /*execute a function presses a key on the keyboard:*/
  inp.addEventListener("keydown", function(e) {
      var x = document.getElementById(this.id + "autocomplete-list");
      if (x) x = x.getElementsByTagName("div");
      if (e.keyCode == 40) {
        /*If the arrow DOWN key is pressed,
        increase the currentFocus variable:*/
        currentFocus++;
        /*and and make the current item more visible:*/
        addActive(x);
      } else if (e.keyCode == 38) { //up
        /*If the arrow UP key is pressed,
        decrease the currentFocus variable:*/
        currentFocus--;
        /*and and make the current item more visible:*/
        addActive(x);
      } else if (e.keyCode == 13) {
        /*If the ENTER key is pressed, prevent the form from being submitted,*/
        e.preventDefault();
        if (currentFocus > -1) {
          /*and simulate a click on the "active" item:*/
          if (x) x[currentFocus].click();
        }
      }
  });

  function addActive(x) {
    /*a function to classify an item as "active":*/
    if (!x) return false;
    /*start by removing the "active" class on all items:*/
    removeActive(x);
    if (currentFocus >= x.length) currentFocus = 0;
    if (currentFocus < 0) currentFocus = (x.length - 1);
    /*add class "autocomplete-active":*/
    x[currentFocus].classList.add("autocomplete-active");
  }

  function removeActive(x) {
    /*a function to remove the "active" class from all autocomplete items:*/
    for (var i = 0; i < x.length; i++) {
      x[i].classList.remove("autocomplete-active");
    }
  }

  function closeAllLists(elmnt) {
      /*close all autocomplete lists in the document,
      except the one passed as an argument:*/
      var x = document.getElementsByClassName("autocomplete-items");
      for (var i = 0; i < x.length; i++) {
        if (elmnt != x[i] && elmnt != inp) {
        x[i].parentNode.removeChild(x[i]);
      }
    }
  }

  /*execute a function when someone clicks in the document:*/
  document.addEventListener("click", function (e) {
      closeAllLists(e.target);
  });
}

function get_data(bot_id, bot_name)
{
    response = $.ajax({
        url:'/chat/get_data/',
        type:'POST',
        async: false,
        data:{
            "bot_id":bot_id,
            "bot_name":bot_name,
        },
        success: function(response){
            return response;
        },
        error: function(error){
            console.log("Report this error", error);
            return {"status":500};
        }
    }).responseJSON;

    if(response["status"]==200){
        return response["sentence_list"];
    }
    else{
        return [];
    }
}

////////////////////////////////////////// voice bot ////////////////////////////////////////////////

var final_transcript = '';
var recognizing = false;
var ignore_onend;

var isSafari = (!!navigator.userAgent.match(/Version\/[\d\.]+.*Safari/))
if(!isSafari){
    if (!('webkitSpeechRecognition' in window)) {
        upgrade();
    } else {
        start_button.style.display = 'inline-block';
        var SpeechRecognition = SpeechRecognition || webkitSpeechRecognition
        // window.SpeechRecognition = window.webkitSpeechRecognition || window.SpeechRecognition;
        var recognition = new SpeechRecognition();
        recognition.continuous = false;
        recognition.interimResults = true;

        recognition.onstart = function() {
            recognizing = true;
            $("#start_button").addClass("pulse");
        };

        recognition.onerror = function(event) {
            $("#start_button").removeClass("pulse");
            if (event.error == 'no-speech') {
                ignore_onend = true;
            }
            if (event.error == 'audio-capture') {
                ignore_onend = true;
            }
            if (event.error == 'not-allowed') {
                ignore_onend = true;
            }
        };

        recognition.onend = function() {
            $("#start_button").removeClass("pulse");
            recognizing = false;
            if (ignore_onend) {
                return;
            }
            if (!final_transcript) {
                return;
            }

        };

        recognition.onresult = function(event) {

        console.log(event.results[0][0].transcript)
        document.getElementById('query').value=event.results[0][0].transcript;
        if (event.results[0].isFinal){
            if(($.trim($('#query').val()) != '') && ($("#query").val()).length<300){
                var sentence = $("#query").val();
                sentence = $($.parseHTML(sentence)).text();
                if (sentence.length == 0) {      // error!
                  $("#query").val("");
                  return;
                }
                $("#query").val("");
                disableInput();
                appendResponseUser(sentence);
                ajaxCallToIndex(sentence, API_SERVER_URL);
            }
            $("#start_button").removeClass("pulse");
            recognition.stop();
          }
        };
    }
  }
else
{
  $("#start_button").css("display", "none");
  $("#submit-img").css("display", "block");
}


$(document).on("click","#start_img", function(e){
  if (recognizing) {
    recognition.stop();
    return;
  }

  final_transcript = '';
  recognition.start();
});

$( "#query" ).keypress(function() {
  $("#start_button").css("display", "none");
  $("#submit-img").css("display", "block");
});

$(document).on("keyup","#query", function(e){
  // alert("keyup")
  if($( "#query" ).val().length==0){
    if(isSafari)
    {
      $("#start_button").css("display", "none");
      $("#submit-img").css("display", "block");
    }
    else
    {
      $("#start_button").css("display", "block");
      $("#submit-img").css("display", "none");
    }
  }else{
    $("#start_button").css("display", "none");
    $("#submit-img").css("display", "block");
  }
});

$(document).on("mouseleave","#query", function(e){
  if($( "#query" ).val().length==0){
    if(isSafari)
    {
      $("#start_button").css("display", "none");
      $("#submit-img").css("display", "block");
    }
    else
    {
      $("#start_button").css("display", "block");
      $("#submit-img").css("display", "none");
    }
    // var SpeechRecognition = SpeechRecognition || webkitSpeechRecognition
    // var recognition = new SpeechRecognition();
    // recognition.stop()
    $("#start_button").removeClass("pulse");
  }
});

handel_radio_input = (e) =>  {

  if($('.parent_Cat').hasClass("animated bounceInRight"))
    $('.parent_Cat').removeClass("animated bounceInRight");
  $('.parent_Cat').addClass("animated bounceOutLeft");

  

  console.log('.parent_Cat');
  console.log(e.value);
  console.log();

  setTimeout(()=>{
    $('.parent_Cat').hide();
    $('.child_Cat.'+e.value).show();
  $('.back').show().attr("id",e.value);


  if($('.child_Cat.'+e.value).hasClass("animated bounceOutLeft"))
    $('.child_Cat.'+e.value).removeClass("animated bounceOutLeft");
  $('.child_Cat.'+e.value).addClass("animated bounceInRight");

  },600);
  
  setTimeout(()=>{
      scroll_to_bottom();
  },1000)
}

handel_back_button = (e) => {
   
     $('#textareal').hide();

    $('.submit').hide();

    var id = e.id;

       $('.back').hide(200);

    if($('.child_Cat.'+id).hasClass("animated bounceInRight"))
      $('.child_Cat.'+id).removeClass("animated bounceInRight");
   $('.child_Cat.'+id).addClass("animated bounceOutLeft");

      

     setTimeout(()=>{
      $('.child_Cat.'+id).hide();
   $('.parent_Cat').show();


   if($('.parent_Cat').hasClass("animated bounceOutLeft"))
    $('.parent_Cat').removeClass("animated bounceOutLeft");
   
   $('.parent_Cat').addClass("animated bounceInRight");

 },600)

   $('input[type="radio"]').prop('checked', false);
  setTimeout(()=>{
      scroll_to_bottom();
  },1000)

}

function toggle_mini_max(e)
{
  $(e).parent().parent().siblings(".chip_without_logo_left_inside").slideToggle();
}

function show_submit_button(){
  $('#textareal').show(200);
  $('.submit').show();
}

// for appending list line 862
function  appendTicketCatagoryList(catagory_list_str , id , Subid)
{  
    //for UI , ANIMATION CONFLIct
    $('.child_Cat').removeClass('child_Cat');
    $('.parent_Cat').removeClass('parent_Cat');
    $('.back').removeClass('back');
    $('.submit').removeClass('submit');
    $('#textareal').remove().removeAttr('id');
    // $('.textarea_prev').remove();
    $('.chip_without_logo_left_inside').addClass("disabled_block");

    console.log(catagory_list_str);
    var Catagories = catagory_list_str.split('$');
    
    console.log(Catagories[0]);
    
    var html =
    '<div class="row CatListBlock chatmessage chip chip_without_logo_left">\
    <div class="row CatHed">\
    <div class="col s9">\
    <p style="margin:0px;">catagory List</p>\
    </div>\
    <div class="col s3">\
    <a class = " mini_max_arrow" onclick = "toggle_mini_max(this)"><i class="material-icons center">expand_more</i></a><div></div>\
    </div>\
    </div>\
    <div class="chip_without_logo_left_inside">';
    
    for (var i = 0; i < Catagories.length - 1; i++) {

        console.log(Catagories[i].split('&')[0] + '\n\n\n');
        var subCats = Catagories[i].split('%')[1];
        var CatID = Catagories[i].split('&')[1].split('%')[0];

        html+=`<p class="catagory_list_item parent_Cat">
                <label>
                    <input name="catagory_list" onclick = "handel_radio_input(this)" value = "catagory`+ CatID +`" type="radio"  />
                    <span class="chip_catagory_spam">`+Catagories[i].split('&')[0]+`</span>
                </label>
              </p>`

        var subCats_list = subCats.split('#');

        for(var j = 0 ; j<subCats_list.length - 1;j++){

              subCatid = subCats_list[j].split('^')[0];
              subCat = subCats_list[j].split('^')[1];

              html+=`<p class = "catagory_list_item child_Cat catagory`+ CatID+`">
                <label>
                    <input name="catagory_list" value = "`+ subCatid +`" type="radio" onclick="show_submit_button()" />
                    <span class="chip_catagory_spam">`+subCat+`</span>
                </label>
              </p>`
        }

    }
    html+=`<div id="textareal" class="input-field marg-top container">
          <textarea  maxlength="80" id="textareall" class="materialize-textarea textarea_prev"></textarea>
          <label for="textareall">Tell me your Issue(optional)</label>
        </div>`
    html+='<a class="back btn-floating btn-floating-small" onclick = "handel_back_button(this)" ><i class="material-icons">arrow_back</i></a>';
    html+='<a class="right submit btn-floating btn-floating-small" onclick = "on_Handle_Ticket_Submit()" ><i class="material-icons">fast_forward</i></a>';
    html+= '</div></div>';
      $("#style-2").append(html);
      $('.submit').hide();
      $('.child_Cat').hide();
      $('.back').hide();
      $('.heading_of_list').addClass("hide");
      $('#textareal').hide();

   console.log(id + "  " + Subid)

    if(id != "x")
    {
      if(Subid == "x")
      {
        $("input[value = 'catagory"+id+"']").click();
      }
      else
      {
        $("input[value = 'catagory"+id+"']").click();

        setTimeout(()=>{
              $("input[value = '"+Subid+"']").click(); 
        },700);
      }
    }
}


function on_Handle_Ticket_Submit(){

    var issue_elaborated = $('#textareal').children('#textareall').val();
  $('#textareal').removeAttr('id');

  console.log(issue_elaborated);
 var ticket_issue_id = $("input[name='catagory_list']:checked").val();

 console.log(ticket_issue_id);

  $('.chip_without_logo_left_inside').addClass("disabled_block");
  $('.submit > i').text("check");
 

 $('.submit').prop("onclick", null).off("click");

console.log(CustomerID);
 //AJAX CALL
  $.ajax({
        url: "/chat/create_ticket/",
        type: "POST",
        data: {
          RoomID,
          BookingID,
          SubCatID : ticket_issue_id,
          CustomerID : CustomerID,
          issue_elaborated
        },
        success: function(response) {

            console.log(response);
            var Message = JSON.parse(response["Api_Response"].join(""))["Message"];
            console.log(Message);

            var tooltip_response = "";
           
            appendResponseServer(Message,false, "", "", tooltip_response);
            scroll_to_bottom();
            // use REGEX for efficiency
            

            site_title = response['site_title'];
            $('.site-title').html(site_title);
        },
        error: function(xhr, textstatus, errorthrown) {
            // console.log("Please report this error: "+errorthrown+xhr.status+xhr.responseText);
        }
    });

}


function extract_status_list_string(status_list){
    var status_array = [];
    var status_list1 = status_list.split("#")
    for(var i = 1;i<status_list1.length;i++)
    {
      var status = {};
      var status_list11 = status_list1[i].split("^");
      status["ServiceTicket"] = status_list11[0];
      status["SubCatogories"] = status_list11[1];
      status["Image"] = status_list11[2];
      status["Description"] = status_list11[3];
      status["Requestdate"] = status_list11[4];
      console.log()
      status_array.push(status);
    }

    append_horizontal_cards(status_array);
}

var idcount = 0;
function append_horizontal_cards(arr)
{

   $('.mybar').removeClass("mybar");
   // $('.horizontal_Scroll').addClass("disabled_block");
   // $('.navigation_status_buttons').addClass('disabled_block');
   html = `<div class="horizontal_Scroll chatmessage carousel carousel-slider center" id = "carousel`+ idcount +`" data-indicators="true">`

   scroll_length = arr.length;
    
    for(var i = 0;i<arr.length;i++)
    {
      var status = arr[i];
      // status["Description"] = "ggggggggggggggggggggggg ggggggggggggggggggggggg gggggggggggggggggggg gggggggggggggggggggg yyyyyyyyyyyyyyyyyyy yyyyyyyyyyyyyyyy tttttttttttttttttttt"
      // console.log(status["ServiceTicket"]+" "+status["SubCatogories"]+" "+status["Image"]+" "+status["Requestdate"]);
      var message = status["Description"].slice(0,120);
      if(status["Description"] != message)
      {
        message += "...";
      }
       html+= `<div class="carousel-item citem`+idcount+`" href="#one!"  id = "`+ idcount +`" no = "`+ i +`">
          <div class="card small mycolor">
                <div class="card-content white-text">
                <div class="row">
                  <div class="center">
                       <img src="`+ status["Image"] +`"class=" circle responsive-img">
                      <p class="card-title">`+status["SubCatogories"]+`</p>
                  </div>
                </div>
                <div class = "row">
                  <p class="inlineblock"><p class="fixed copy chip ">copied</p><span data-position="left" data-tooltip="Ticket Token" class="tooltipped chip mini_max_arrow" onclick = "copyText(this)">`+status["ServiceTicket"]+`</span></p>
                </div>
                  <p class="flow-text">`+ message +`</p>
                </div>
                <div class="card-action row mycolor">
                  <div class = "col s6"><span data-position="top" data-tooltip="Requested Date" class="tooltipped chip mini_max_arrow left">`+status["Requestdate"]+`</span></div>
                  <div class = "col s6"><span class="chip mini_max_arrow right" token = "`+status["ServiceTicket"].split('R')[1]+`" onclick = "cheack_Ticket_Status_By_Token(this)">Check Status</span></div>
                </div>
              </div>
        </div>`
    }
 html += `</div>`;

 html += ` <div class="progress-container chatmessage">
    <div class="progress-bar mybar" id = "mybar`+ idcount +`"></div>
  </div> `;

 html+=`<div class="center chatmessage navigation_status_buttons navigate`+idcount+`"><a class = "btn-floating-small btn-floating mini_max_arrow" leng = "`+ scroll_length +`" id = "`+ idcount +`" onclick = "prev_carosol(this)"><i class="material-icons center">arrow_back</i></a>
 <a class = "btn-floating btn-floating-small mini_max_arrow" leng = "`+ scroll_length +`" id = "`+ idcount +`" onclick = "next_carosol(this)"><i class="material-icons center">arrow_forward</i></a>
 </div><div></div>`

  $("#style-2").append(html);
  $('#carousel'+idcount).carousel();
  $('#carousel'+idcount+'.carousel-slider').carousel({fullWidth: true});
  $('.tooltipped').tooltip({delay: 50});
  $('.copy').hide();
  $('.carousel.carousel-slider .carousel-item').css({"width":"80%" , "margin-left":"10%"});
  if(scroll_length == 1)
  {
    console.log($('.navigate'+idcount));
    $('.navigate'+idcount).hide().addClass("disabled_block");
  }
  
  
  idcount++;
  count = 0;
}


function next_carosol(e){
  // count = (count + 1)%scroll_length;
  // console.log(count);
  var idpresssed = $(e).attr("id");
  var leng = $(e).attr("leng");
  $(e).parent().prev().prev().carousel('next');
  scroll(idpresssed , leng , 1);
}

function prev_carosol(e){
  // count = (count - 1)%scroll_length;
  // if(count<0)
  // count += scroll_length;
  var idpresssed = $(e).attr("id");
  var leng = $(e).attr("leng");
  // console.log(count);
  $(e).parent().prev().prev().carousel('prev');
  scroll(idpresssed , leng , 0);
}


function scroll(idpresssed , leng , flag)
{
  // console.log(idpresssed);
  setTimeout(function(){
   count = $('#'+idpresssed+'.active').attr("no");
    var scroll_length = leng;
  // console.log(count + " " + scroll_length);
  if(flag == 1)
    count++;
  else
    count--;
  var scrolled = (count / scroll_length)*100;
  document.getElementById("mybar"+idpresssed).style.width = scrolled + "%";
  },100)
 
}

function copyText(element)
{
    
      var $temp = $("<input>");
      $("body").append($temp);
      $temp.val($(element).text()).select();
      document.execCommand("copy");
      $temp.remove();
      
      $(element).prev().show();
      $(element).prev().addClass("animated fadeInUp");
      setTimeout(()=>{
        $(element).prev().hide();
        $(element).prev().removeClass("animated fadeInUp");
      },500);
      
}

function cheack_Ticket_Status_By_Token(e)
{
  var token = $(e).attr("token")
  $.ajax({
        url: "/chat/cheack_ticket_status/",
        type: "POST",
        data: {
          token
        },
        success: function(response) {

            console.log(response);
            var Data = JSON.parse(response["Api_Response"].join(""))["Data"];
            var Message = ""
            if(Data.length < 2)
            {
              Message = "In waiting<br/><br/>Currently we are looking into the issue your problem is alredy considered by us.<br/>";
            }
            else
            {
              Message = "Confirmed<br/>";
              Message += "On - " + Data[1]["CreatedDate"].split(" ")[0] + "<br/><br/>";
              Message += Data[1]["ReplyMessage"];
            }
            console.log(Message);

            var tooltip_response = "";
           
            appendResponseServer(Message,false, "", "", tooltip_response);
            scroll_to_bottom();
            // use REGEX for efficiency
            

            site_title = response['site_title'];
            $('.site-title').html(site_title);
        },
        error: function(xhr, textstatus, errorthrown) {
            // console.log("Please report this error: "+errorthrown+xhr.status+xhr.responseText);
        }
    });
}


function showForm(){

  var html = `<div class="row formbox chatmessage formcolor darken-4">
    <form class="col s12">
      <div class="row">
        <div class="input-field col s12">
          <i class="material-icons prefix" style = "color:#AB2567 !important;">email</i>
          <input id="icon_prefix" type="text" class="validate black-text"> 
          <label for="icon_prefix" class="black-text">Email</label>
        </div>
        <div class="input-field col s12">

          <div class="one">
          <i class="material-icons prefix" style = "color:#AB2567 !important;">fingerprint</i>
          <input id="i" type="Password" class="validate black-text">
          <label for="i" class = "black-text">Password</label>
          <a class="right" href="#" onclick = "changeVisibilityPass(this)" ><i class="material-icons white-text">visibility_off</i></a>
          </div>

        </div>
         <div class="input-field no-marg-top col s12">
          <p class = "red-text darken-4 errormsg left">error message<p>
          <a class="btn-floating right" style = "background-color:#AB2567 !important;" onclick = "sendDataEmailPass(this)"><i class="material-icons">send</i></a>
        </div>
      </div>
    </form>
  </div>`

  $("#style-2").append(html);
  $('.errormsg').hide();
}


// ajaxCallToIndex(sentence, API_SERVER_URL);
// visibility
// visibility_off

function changeVisibilityPass(e)
{
  if($(e).children(".material-icons").text() == "visibility")
  {
    $(e).children(".material-icons").text("visibility_off");
    $(e).prev().prev().attr("type","Password");
  }
  else
  {
    $(e).children(".material-icons").text("visibility");
    $(e).prev().prev().attr("type","text");
  }
}

const validate = (email) => {
    const expression = /(?!.*\.{2})^([a-z\d!#$%&'*+\-\/=?^_`{|}~\u00A0-\uD7FF\uF900-\uFDCF\uFDF0-\uFFEF]+(\.[a-z\d!#$%&'*+\-\/=?^_`{|}~\u00A0-\uD7FF\uF900-\uFDCF\uFDF0-\uFFEF]+)*|"((([ \t]*\r\n)?[ \t]+)?([\x01-\x08\x0b\x0c\x0e-\x1f\x7f\x21\x23-\x5b\x5d-\x7e\u00A0-\uD7FF\uF900-\uFDCF\uFDF0-\uFFEF]|\\[\x01-\x09\x0b\x0c\x0d-\x7f\u00A0-\uD7FF\uF900-\uFDCF\uFDF0-\uFFEF]))*(([ \t]*\r\n)?[ \t]+)?")@(([a-z\d\u00A0-\uD7FF\uF900-\uFDCF\uFDF0-\uFFEF]|[a-z\d\u00A0-\uD7FF\uF900-\uFDCF\uFDF0-\uFFEF][a-z\d\-._~\u00A0-\uD7FF\uF900-\uFDCF\uFDF0-\uFFEF]*[a-z\d\u00A0-\uD7FF\uF900-\uFDCF\uFDF0-\uFFEF])\.)+([a-z\u00A0-\uD7FF\uF900-\uFDCF\uFDF0-\uFFEF]|[a-z\u00A0-\uD7FF\uF900-\uFDCF\uFDF0-\uFFEF][a-z\d\-._~\u00A0-\uD7FF\uF900-\uFDCF\uFDF0-\uFFEF]*[a-z\u00A0-\uD7FF\uF900-\uFDCF\uFDF0-\uFFEF])\.?$/i;

    return expression.test(String(email).toLowerCase())
}

function sendDataEmailPass(e)
{
  var email = $(e).parent().parent().prev().prev().children("#icon_prefix").val();
  var Pass = $(e).parent().parent().prev().children(".one").children("#i").val();
  
  var Data_str = email + "/" + Pass;

  console.log(Data_str);

  if(email!="" && Pass!="")
    {

      if(!validate(email))
      {
          passError("wrong email id" , e);
      }
      else
      {
        ajaxCallToIndex(Data_str, API_SERVER_URL);
        $('.formbox').remove();
      }
    }
  else
    passError("both fields are required!!" , e);
}

function passError(msg , e)
{
    $(e).parent().prev().show();
    $(e).parent().prev().addClass("animated shake");
   $(e).parent().prev().text(msg);
   setTimeout(()=>{
    $(e).parent().prev().removeClass("animated shake");
   },1000);
}

function again_Login(msg)
{
  var msgg = $($('.user_msg')[$('.user_msg').length-1]).children('span').text();
  ajaxCallToIndex(msgg, API_SERVER_URL);
  $('.formbox').remove();
}



function append_invoice_table(invoice_str)
{

  var invoice_data_list = invoice_str.split("$");

  console.log(invoice_data_list.length);

  var html = `<div class = "invoice_table_table chatmessage">`;

  html += `<table class="highlight entered">
        <thead class="invoice_table_thead"> 
          

          <tr>
          <th>InvoiceID</th> 
          `  

             for(var i = 0;i<invoice_data_list.length-1;i++)
  {
     var data = invoice_data_list[i].split("%");
     html += `
            <td class="center">`+ data[0]+`</td>`

  }


           html += `
          </tr>

          <tr>
          <th>BillNO</th> 
          `  

           for(var i = 0;i<invoice_data_list.length-1;i++)
  {
     var data = invoice_data_list[i].split("%");
     html += `
            <td class = "center BillNo">`+ data[1]+`</td>
          `

  }

          html += `          
          </tr>

           <tr>
           <th>BillDate</th>`

          for(var i = 0;i<invoice_data_list.length-1;i++)
  {
     var data = invoice_data_list[i].split("%");
     html += `
            <td class = "center">`+ data[2]+`</td>
          `

  }

           html +=  `</tr>

           <tr>
           <th>BookingID</th>`

             for(var i = 0;i<invoice_data_list.length-1;i++)
  {
     var data = invoice_data_list[i].split("%");
     html += ` 
            <td class = "center">`+ data[3]+`</td>
          `

  }

          html += `</tr>

           <tr>
          <th>BookingCode</th>`

           for(var i = 0;i<invoice_data_list.length-1;i++)
  {
     var data = invoice_data_list[i].split("%");
     html += `
            <td class="center">`+ data[4]+`</td>
          `

  }

          html += `</tr>

           <tr>
          <th>Duration</th>`

           for(var i = 0;i<invoice_data_list.length-1;i++)
  {
     var data = invoice_data_list[i].split("%");
     html += `
            <td class="center">`+ data[5]+`</td>
          `

  }

          html += `</tr>

           <tr>
           <th>TotalAmount</th>`

            for(var i = 0;i<invoice_data_list.length-1;i++)
  {
     var data = invoice_data_list[i].split("%");
     html += `
            <td class = "center">`+data[7]+`</td>
          `

  }

          html += `</tr>`



            html += `</tr>

           <tr>
           <th>ServiceTaxPercentage</th>`

          for(var i = 0;i<invoice_data_list.length-1;i++)
          {
             var data = invoice_data_list[i].split("%");
             html += `
                    <td class = "center">`+data[8]+`</td>
                  `

          }

          html += `</tr>`


            html += `</tr>

           <tr>
           <th>DiscountPercentage</th>`

          for(var i = 0;i<invoice_data_list.length-1;i++)
          {
             var data = invoice_data_list[i].split("%");
             html += `
                    <td class = "center">`+data[9]+`</td>
                  `

          }

          html += `</tr>`


          
            html += `</tr>

           <tr>
           <th>DueAmount</th>`

          for(var i = 0;i<invoice_data_list.length-1;i++)
          {
             var data = invoice_data_list[i].split("%");
             html += `
                    <td class = "center">`+data[10]+`</td>
                  `

          }

          html += `</tr>`


            html += `</tr>

           <tr>
           <th>ElectricityAmount</th>`

          for(var i = 0;i<invoice_data_list.length-1;i++)
          {
             var data = invoice_data_list[i].split("%");
             html += `
                    <td class = "center">`+data[11]+`</td>
                  `

          }

          html += `</tr>`


            html += `</tr>

           <tr>
           <th>FoodCharge</th>`

          for(var i = 0;i<invoice_data_list.length-1;i++)
          {
             var data = invoice_data_list[i].split("%");
             html += `
                    <td class = "center">`+data[12]+`</td>
                  `

          }

          html += `</tr>`



            html += `</tr>

           <tr>
           <th>Laundry</th>`

          for(var i = 0;i<invoice_data_list.length-1;i++)
          {
             var data = invoice_data_list[i].split("%");
             html += `
                    <td class = "center">`+data[13]+`</td>
                  `

          }

          html += `</tr>`


            html += `</tr>

           <tr>
           <th>Refund</th>`

          for(var i = 0;i<invoice_data_list.length-1;i++)
          {
             var data = invoice_data_list[i].split("%");
             html += `
                    <td class = "center">`+data[14]+`</td>
                  `

          }

          html += `</tr>`



       html += ` </thead> <tbody>`

 
 
 html += ` </tbody>
      </table></div>`
  
  $("#style-2").append(html);
   $('.tooltipped').tooltip();
}


months = {
  0 : "Jan",
  1 : "Feb",
  2 : "Mar",
  3 : "Apr",
  4 : "May",
  5 : "Jun",
  6 : "July",
  7 : "Aug",
  8 : "Sept",
  9 : "Oct",
  10 : "Nov",
  11 : "Dec"
}

var d = new Date();
var currentyear = d.getFullYear();

var currentmonth = d.getMonth();

var till = 11;

var from = currentyear - 30;

function appendAskMonth(year){

    console.log("Calender");
    eventclasses = ["yearlist","monthlist" , "month" , "year" , "monthlistitem"];

   $('.monthlist').hide();
   $('.yearlist').hide();


   for(var i = 0;i<eventclasses.length;i++)
   {
    $('.'+eventclasses[i]).removeClass(eventclasses[i]);
   }
   // $('.monthlist').removeClass("monthlist");
   // $('.yearlist').removeClass("yearlist");
   // $('.month').removeClass("month");
   // $('.year').removeClass("year");
   $('.monthlistitem').removeClass("monthlistitem");


   $('.calender_m_y').addClass("disabled_block");


    if(year == currentyear)
    {
      till = currentmonth;
      console.log(till);
    }
    else
    {
      till = 11;
    }



    var html = `

      <div class = "calender_m_y chatmessage">
        <div class = "calender_upper">
            <div class = "row"> 
                <div class = "col s1 center">
                    <div class = "circle">
                    </div>
                </div>

                <div class = "col s1 offset-s10 center">
                     <div class = "circle">
                    </div>
                </div>
            </div>
        </div>

        <div class = "calender_lower">
           <div class = "row">
               <div class = "col s5 center">
                    <p class = "month monthh" onclick = "showmonthlist()">Select month</p>
               </div>

               <div class = "col s5 center">
                   <p class = "year yearr" onclick = "showyearlist()"> `+ year +` </p>
               </div>

               <div class = "col s2">
                  <button class = "btn-floating btn-floating-small-calender" onclick = "sendMonthYear()">
                    <i class = "material-icons">fast_forward</i>
                  </button>
               </div>
           </div>
        </div>


         <div class = "datablock">

         <div class = "row">
               `
               


    html += `      
        <div class = " col s6 list monthlist collection black-text">
         `

        html +=  `
        
        </div>   


        <div class = " col s6 list yearlist collection black-text">
         
         `
            for(var i  = from ; i<=currentyear;i++)
            {
              html += ` <a href="#!" class="collection-item" onclick = "selectyear(this)">`+ i +`</a>`;
            }

         html += `

       
        </div>   
         `  
               html += `
               </div>
         </div> 
      </div>
    `
    $("#style-2").append(html);
    $(".monthlist").hide();
    $(".yearlist").hide();
    rendermonths(till);

}

function showmonthlist()
{
  console.log("clicked");
  $('.monthlist').slideToggle();
  scroll_to_bottom();
}

function showyearlist()
{
  console.log("clicked year");
  $('.yearlist').slideToggle();
  scroll_to_bottom();
}

function selectmonth(e)
{
  var monthselected = $(e).text();
  $('.month').text(monthselected);
  console.log(monthselected);
}

function selectyear(e)
{
  var yearselected = $(e).text();
  $('.year').text(yearselected);

  if(yearselected == currentyear)
  {
    till = currentmonth;
    $('.monthlistitem').remove();
    rendermonths(till);
  }
  else
  {
    till = 11; 
    $('.monthlistitem').remove();
    rendermonths(till);
  }

  console.log(yearselected);
}

function rendermonths(till)
{
  var html = '';

  for(var i = 0 ; i<= till ; i++)
          {
            var mon = months[i];
            html += `<a href="#!" class="collection-item monthlistitem" onclick = "selectmonth(this)" >`+ mon +`</a>`
          }

  $('.monthlist').append(html);
}


function sendMonthYear(){

  var month = $('.month').text();
  console.log(month);
  if(month == "Select month")
  {
      $('.month').addClass("animated wobble");
      setTimeout(function(){
          $('.month').removeClass("animated wobble");
      },1000)
  }
  else{
    var msg = month +  " , " + $('.year').text();
    eventclasses = ["yearlist","monthlist" , "month" , "year" , "monthlistitem"];

   $('.monthlist').hide();
   $('.yearlist').hide();


   for(var i = 0;i<eventclasses.length;i++)
   {
    $('.'+eventclasses[i]).removeClass(eventclasses[i]);
   }
   // $('.monthlist').removeClass("monthlist");
   // $('.yearlist').removeClass("yearlist");
   // $('.month').removeClass("month");
   // $('.year').removeClass("year");
   $('.monthlistitem').removeClass("monthlistitem");


   $('.calender_m_y').addClass("disabled_block");
   ajaxCallToIndex(msg, API_SERVER_URL);

  }
   
}
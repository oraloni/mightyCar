const char car_html[] PROGMEM  = R"rawliteral(
        <!DOCTYPE html>
        <html lang="en">
            <head>
                <title>Mighty</title>
                <meta name="viewport" content="width=device-width, initial-scale=0.78, user-scalable=false">
                <!-- <meta name="viewport" content="width=device-width, initial-scale=1, user-scalable=false"> -->
                <link rel="stylesheet" href="https://use.fontawesome.com/releases/v5.7.2/css/all.css"
                    integrity="sha384-fnmOCqbTlWIlj8LyTjo7mOUStjsKC4pOpQbqyi7RrhN7udi9RwhKkMHpvLbHG9Sr"
                    crossorigin="anonymous">
            </head>
            <style>
                html {
                    margin: auto;
                    height: 100%;
                    width: 100%;
                }
                h1 {
                    text-align: center;
                    color:rgb(128, 128, 128);
                    margin: auto;
                    font-size: 16px;
                    }

                button{
                    height: 100px;
                    width: 100px;
                    background-color: #4CAF50; /* Green */
                    border: none;
                    color: white;
                    text-align: center;
                    font-size: 50px;
                    margin: 5px;
                    }

                .top_grid{
                    height: 100%;
                    width: 100%;
                }
                    
               .buttons_grid {
                        grid-column-start: 0;
                        grid-column-end: 1;
                        grid-row-start: 0;
                        grid-row-end: 1;
                        grid-auto-columns: minmax(auto, 120px);
                 } 

               .esp32_cam {
                        grid-column-start: 1;
                        grid-column-end: 2;
                        grid-row-start: 0;
                        grid-row-end: 1;
                 }

              .slider_box {
                        grid-column-start: 0;
                        grid-column-end: 1;
                        grid-row-start: 1;
                        grid-row-end: 2;
                        align-self: center;
                        justify-self: center;
                 }
                 .u_l_b{

                        grid-column-start: 0;
                        grid-column-end: 1;
                        grid-row-start: 0;
                        grid-row-end: 1;
                        align-self: center;
                        justify-self: center;    
                 }
                 
                 .f_b {
                        grid-column-start: 1;
                        grid-column-end: 2;
                        grid-row-start: 0;
                        grid-row-end: 1;
                        align-self: center;
                        justify-self: center;
                 }

                 .u_r_b{

                        grid-column-start: 2;
                        grid-column-end: 3;
                        grid-row-start: 0;
                        grid-row-end: 1;
                        align-self: center;
                        justify-self: center;    
                 }

                 
                 .l_b {
                        grid-column-start: 0;
                        grid-column-end: 1;
                        grid-row-start: 1;
                        grid-row-end: 2;
                        align-self: start;
                 }

                 
                 .s_b {
                        grid-column-start: 1;
                        grid-column-end: 2;
                        grid-row-start: 1;
                        grid-row-end: 2;
                        align-self: center;
                        justify-self: center;
                 }

                 
                 .r_b {
                        grid-column-start: 2;
                        grid-column-end: 3;
                        grid-row-start: 1;
                        grid-row-end: 2;
                        align-self: start;
                 }

                 
                 .b_b {
                        grid-column-start: 1;
                        grid-column-end: 2;
                        grid-row-start: 2;
                        grid-row-end: 3;
                        align-self: center;
                        justify-self: center;
                 }
                    
                 button.up_button{
                        //margin-left: 120px;
                        border-top-left-radius: 50px;
                        border-top-right-radius: 50px;
                        text-align: center;
                        }
                 button.down_button{
                        //margin-left: 120px;
                        border-bottom-left-radius: 50px;
                        border-bottom-right-radius: 50px;
                        text-align: center;
                        }
                 button.right_button{
                        border-top-right-radius: 50px;
                        border-bottom-right-radius: 50px;
                        text-align: center;
                        }
                 button.left_button{
                        border-top-left-radius: 50px;
                        border-bottom-left-radius: 50px;
                        text-align: center;
                        }
                 button.stop_button{
                        border-top-right-radius: 10px;
                        border-bottom-right-radius: 10px;
                        border-top-left-radius: 10px;
                        border-bottom-left-radius: 10px;
                        text-align: center;
                        }
                button.uturn_left_button{
                        border-radius: 100px;
                        height: 60px;
                        width: 60px;
                        font-size: 35px;
                        text-align: center;
                        }
                        
                button.uturn_right_button{
                        border-radius: 100px;
                        height: 60px;
                        width: 60px;
                        font-size: 35px;
                        text-align: center;
                        }



                 input[type="range"]{
                        -webkit-appearance:none;
                        width:200px;
                        height:30px;
                        
                        margin-top: 30px;
                        padding-right: 90px;
                        border-radius: 20px;
                        background: linear-gradient(to right, #4CAF50 0%, #9A2720 100%);
                        background-size:250px 60px;
                        background-position:center;
                        background-repeat:no-repeat;
                        overflow:hidden;
                        outline: none;
                        position: relative;
                    }
                input[type="range"]::-webkit-slider-thumb{
                        -webkit-appearance:none;
                        width:20px;
                        height:60px;
                        
                        border-radius: 10px;
                        
                        background:#F26B5E;
                        position:relative;
                        z-index:3;
                        box-shadow:0 0 5px 0 rgba(0,0,0,0.3);
                    }
                    
               img {
                border-radius: 30;
               }

               div.esp_cam {
                    height: 300;
                    width: 300;
                    border-radius: 30;
                 }
                      
        @media screen and (max-width:800px)
               and (orientation:portrait){
                /* Mobile portrait style */
                body {
                    height: auto;
                    width: auto;
                }
                h1 {
                    color: blue;
                }

                button{
                    text-align: center;
                }

                
                button.uturn_left_button{
                    padding-right: 60px;
                    text-align: center; 
                }

                button.uturn_right_button{
                    padding-right: 60px;
                    text-align: center; 
                }

                div.esp_cam {
                    display: none;
                 }

               img {
                    display: none;
               }

        }

       @media screen and (max-width:800px) 
                     and (orientation:landscape){
                /* Mobile landscape style */

                html {
                    height: auto;
                    width: auto;
                }
                h1 {
                    color: red;
                }
                
               div.esp32_cam {
                        grid-column-start: 2;
                        grid-column-end: 3;
                        grid-row-start: 0;
                        grid-row-end: 1;
                 }
                
                div.buttons_grid{
                        grid-column-start: 0;
                        grid-column-end: 1;
                        grid-row-start: 0;
                        grid-row-end: 1;
                }

                div.slider_box {
                        grid-column-start: 1;
                        grid-column-end: 2;
                        grid-row-start: 0;
                        grid-row-end: 1;
                 }

                button{
                    text-align: center;
                }

                button.uturn_left_button{
                    padding-right: 60px;
                    text-align: center; 
                }

                button.uturn_right_button{
                    padding-right: 60px;
                    text-align: center; 
                }

                 slider {
                    orient="vertical";
                 }
                
        }
            </style>
            
          <body style="position:fixed; font-family: 'Gill Sans', 'Gill Sans MT', Calibri, 'Trebuchet MS', sans-serif;
                font-size: x-large;">
                
            <h1>Mighty Car</h1>
            <br>
           <div class="top_grid" style="display: grid;">
                <div class="buttons_grid", style="display: grid;">                  

                    <div class="u_l_b">
                    <button class="uturn_left_button" id="u_l_button" type="button">
                            <i class="fas fa-undo" style="color:#FFFF49; text-align: center;"></i></a>
                     </button>
                    </div> 
                    
                    <div class="f_b">
                    <button class="up_button" id="f_button" type="button">
                        <i class="fas fa-arrow-up" style="color:#FFFF49; text-align: center;"></i></a>
                     </button>
                     </div>

                    <div class="u_r_b">
                    <button class="uturn_right_button" id="u_r_button" type="button">
                            <i class="fas fa-redo" style="color:#FFFF49; text-align: center;"></i></a>
                     </button>
                    </div> 
                    <br>

                    <div class="l_b">
                    <button class="left_button" id="l_button" type="button">
                        <i class="fas fa-arrow-left" style="color:#FFFF49; text-align: center;"></i></a>
                    </button>
                    </div>

                    <div class="s_b">
                    <button class="stop_button" id="s_button" type="button">
                        <i class="far fa-stop-circle" style="color:#FFFF49; text-align: center;"></i></a>
                    </button>
                    </div>

                    <div class="r_b">
                    <button class="right_button" id="r_button" type="button">
                         <i class="fas fa-arrow-right" style="color:#FFFF49; text-align: center;"></i></a>
                    </button>
                    </div>
                    <br>

                    <div class="b_b">
                    <button class="down_button" id="b_button" type="button">
                        <i class="fas fa-arrow-down" style="color:#FFFF49; text-align: center;"></i></a>
                    </button>
                    </div>
             </div> <!-- end of buttons grid div -->
                    
                    <div class="esp32_cam" 
                        style="margin-bottom: 10px; height: 100; width: 100; border-radius: 30;">
                            <img src="http://10.0.0.77" width="300" height="300" 
                            style="border:3px solid black; border-radius: 10px; margin: 10px;">
                    </div>     
            <br>
            <div class="slider_box">
            <input type="range" min="1" max="100" value="50" class="slider" id="speedSlider">
                <datalist id="a-values">
                <option value="10" label="Low">
                <option value="90" label="High">
            </datalist>
            <div>

            </div> <!-- end of top_grid div -->
            
            <script>


                var f_button = document.getElementById("f_button");
                var b_button = document.getElementById("b_button");
                var l_button = document.getElementById("l_button");
                var r_button = document.getElementById("r_button");
                var s_button = document.getElementById("s_button");
                var l_uturn_button = document.getElementById("u_l_button");
                var r_uturn_button = document.getElementById("u_r_button");

                
               function processReturn() {
                      try {
                         if (xhttp.readyState == 4 && xhttp.status == 200) {
                                console.info("request sent, response: " + xhttp.responeText);
                             }
                         else
                                {
                                console.info("problem with request");
                                }
                            }
                     catch(e)
                        {
                            alert("Caught Exception: " + e.description);
                        }
                 }

                l_uturn_button.addEventListener('click' , event => {
                      var xhttp = new XMLHttpRequest();
                      console.info("command: <");    
                      //xhttp.onreadystatechange = processReturn;                           
                      xhttp.open("GET", "/special?cmd=" + 'Y', true);
                      xhttp.send(null);
                });

                r_uturn_button.addEventListener('click' , event => {
                      var xhttp = new XMLHttpRequest();
                      console.info("command: >");    
                      //xhttp.onreadystatechange = processReturn;                           
                      xhttp.open("GET", "/special?cmd=" + 'X', true);
                      xhttp.send(null);
                });
                 
                f_button.addEventListener('click' , event => {
                      var xhttp = new XMLHttpRequest();
                      console.info("command: F");    
                      //xhttp.onreadystatechange = processReturn;                           
                      xhttp.open("GET", "/car?cmd=" + 'F', true);
                      xhttp.send(null);
                });

                r_button.addEventListener('click' , event => {
                      var xhttp = new XMLHttpRequest();
                      console.info("command: R");    
                      //xhttp.onreadystatechange = processReturn;                           
                      xhttp.open("GET", "/car2?cmd=" + 'R', true);
                      xhttp.send(null);
                });

                l_button.addEventListener('click' , event => {
                      var xhttp = new XMLHttpRequest();
                      console.info("command: L");    
                      //xhttp.onreadystatechange = processReturn;                           
                      xhttp.open("GET", "/car2?cmd=" + 'L', true);
                      xhttp.send(null);
                });

                b_button.addEventListener('click' , event => {
                      var xhttp = new XMLHttpRequest();
                      console.info("command: B");    
                      //xhttp.onreadystatechange = processReturn;                           
                      xhttp.open("GET", "/car?cmd=" + 'B', true);
                      xhttp.send(null);
                });

                s_button.addEventListener('click' , event => {
                      var xhttp = new XMLHttpRequest();
                      console.info("command: S");    
                      //xhttp.onreadystatechange = processReturn;                           
                      xhttp.open("GET", "/car?cmd=" + 'S', true);
                      xhttp.send(null);
                });

                var slider = document.getElementById("speedSlider");
               
                slider.addEventListener('change' , event => {
                      var xhttp = new XMLHttpRequest();
                      var slider_val = String(slider.value);
                      console.info("slider " + slider_val);    
                      //xhttp.onreadystatechange = processReturn;                           
                      xhttp.open("GET", "/car1?speed=" + slider_val, true);
                      xhttp.send(null);
                });
                
            </script>

          </body>
        </html> 
)rawliteral";

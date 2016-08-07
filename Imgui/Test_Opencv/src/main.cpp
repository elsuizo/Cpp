/* -------------------------------------------------------------------------
   @file main.cpp

   @date 08/03/16 17:42:55
   @author Martin Noblia
   @email martin.noblia@openmailbox.org

   @brief

   @detail

Licence:
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or (at
your option) any later version.

This program is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
General Public License for more details.

You should have received a copy of the GNU General Public License
---------------------------------------------------------------------------*/
#include "../external/imgui/imgui.h"
//#include "../external/imgui-SFML.h"


// #include <SFML/Graphics/RenderWindow.hpp>
// #include <SFML/System/Clock.hpp>
// #include <SFML/Window/Event.hpp>

#include<opencv2/highgui/highgui.hpp>
//#include<opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include<stdio.h>
#include <iostream>
#include<math.h>
#include<time.h>
using namespace cv;
using namespace std;
int main()
{
  Mat img;
  img = imread("/home/elsuizo/images/motivation.jpg", CV_LOAD_IMAGE_COLOR);
  //float color[3] = { 0.f, 0.f, 0.f };

  // let's use char array as buffer, see next part
  // for instructions on using std::string with ImGui
  //char windowTitle[255] = "ImGui + SFML = <3";


  namedWindow("Imagen");

  ImGui::Begin("Sample window"); // begin window
  ImGui::End(); // end window

  // Background color edit
  // if (ImGui::ColorEdit3("Background color", color)) {
  //     // this code gets called if color value changes, so
  //     // the background color is upgraded automatically!
  //     bgColor.r = static_cast<sf::Uint8>(color[0] * 255.f);
  //     bgColor.g = static_cast<sf::Uint8>(color[1] * 255.f);
  //     bgColor.b = static_cast<sf::Uint8>(color[2] * 255.f);
  // }

  // Window title text edit
  //ImGui::InputText("Window title", windowTitle, 255);

  // if (ImGui::Button("Update window title")) {
  //   // this code gets if user clicks on the button
  //   // yes, you could have written if(ImGui::InputText(...))
  //   // but I do this to show how buttons work :)
  //   window.setTitle(windowTitle);
  // }

  //window.clear(bgColor); // fill background with color
  imshow("Imagen",img);
  ImGui::Render();
  waitKey(0);
  destroyAllWindows();
  //window.display();


}

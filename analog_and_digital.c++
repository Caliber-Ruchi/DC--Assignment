#include <iostream>
#include <vector>
#include "SDL2/SDL.h"
#include <string>
#include <unordered_map>
#include <cmath>
#include "SDL2/SDL_ttf.h"

void input_b8zs(int *arr, int size)
{
    int count = 0;
    int v = 2;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == 1)
            count = 0;
        if (arr[i] == 0)
            count++;
        if (count == 8)
        {
            arr[i - count + 1] = 0;
            arr[i - count + 2] = 0;
            arr[i - count + 3] = 0;
            arr[i - count + 4] = v;
            arr[i - count + 5] = 1;
            arr[i - count + 6] = 0;
            arr[i - count + 7] = v;
            arr[i - count + 8] = 1;
            count = 0;
        }
    }
}

void input_hdb3(int *arr, int size)
{
    int count1 = 0;
    int count0 = 0;
    int v = 2;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == 1)
        {
            count0 = 0;
            count1++;
        }
        if (arr[i] == 0)
            count0++;

        if (count0 == 4)
        {
            if (count1 % 2 == 0)
            {
                arr[i - count0 + 1] = 1;
                arr[i - count0 + 4] = v;
            }
            if (count1 % 2 == 1)
            {
                arr[i - count0 + 4] = v;
            }
            count0 = 0;
            count1 = 0;
        }
    }
}

// ----------DIGITAL-------------
void Non_Return_To_Zero_Level(int *test, int size, SDL_Renderer *gRenderer, int scale)
{
    SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, 255);
    // SDL_RenderDrawLine(gRenderer, 0, 300, 800, 300);
    SDL_SetRenderDrawColor(gRenderer, 0, 0, 255, 255);
    int xx = 0, yy = 260;
    for (int i = 0; i < size - 1; i++)
    {
        // SDL_RenderDrawLine(gRenderer, (i*2), 260, (i*2), 300);
        // SDL_RenderDrawLine(gRenderer, i*2, 260, (i*2+scale), 260);
        // SDL_RenderDrawLine(gRenderer, scale+(i*2), 260, scale+(i*2), 300);
        // SDL_RenderDrawLine(gRenderer, scale+(i*2), 300, scale+(i*2+scale), 300);

        if (test[i] == 0)
        {
            SDL_RenderDrawLine(gRenderer, xx, 280, (xx) + scale, 280);
            xx = xx + scale;
        }
        else
        {
            SDL_RenderDrawLine(gRenderer, (xx), 320, (xx + scale), 320);
            xx = xx + scale;
        }

        if (test[i + 1] != test[i])
        {
            SDL_RenderDrawLine(gRenderer, (xx), 280, (xx), 320);
        }
    }

    if (test[size - 1] == 1)
    {
        SDL_RenderDrawLine(gRenderer, (xx), 320, (xx + scale), 320);
    }
    else
    {
        SDL_RenderDrawLine(gRenderer, xx, 280, (xx) + scale, 280);
    }
}

void Non_Return_To_Zero_Inverted(int *test, int size, SDL_Renderer *gRenderer, int scale)
{
    SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, 255);
    // SDL_RenderDrawLine(gRenderer, 0, 300, 800, 300);
    SDL_SetRenderDrawColor(gRenderer, 0, 0, 255, 255);
    int xx = 0, yy = 260;
    bool change = false;
    // std::vector<int>y(260,300);
    int y;
    for (int i = 0; i < size - 1; i++)
    {
        y = change ? 320 : 280;
        // SDL_RenderDrawLine(gRenderer, (i*2), 260, (i*2), 300);
        // SDL_RenderDrawLine(gRenderer, i*2, 260, (i*2+scale), 260);
        // SDL_RenderDrawLine(gRenderer, scale+(i*2), 260, scale+(i*2), 300);
        // SDL_RenderDrawLine(gRenderer, scale+(i*2), 300, scale+(i*2+scale), 300);

        SDL_RenderDrawLine(gRenderer, xx, y, (xx) + scale, y);
        xx = xx + scale;

        if (test[i + 1] == 1)
        {
            SDL_RenderDrawLine(gRenderer, (xx), 280, (xx), 320);
            change = !change;
        }
    }
    y = change ? 320 : 280;
    if (test[size - 1] == 1)
    {
        SDL_RenderDrawLine(gRenderer, (xx), y, (xx + scale), y);
    }
    else
    {
        SDL_RenderDrawLine(gRenderer, xx, y, (xx) + scale, y);
    }
}

void Manchaster(int *test, int size, SDL_Renderer *gRenderer, int scale)
{
    SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, 255);
    // SDL_RenderDrawLine(gRenderer, 0, 300, 800, 300);
    SDL_SetRenderDrawColor(gRenderer, 0, 0, 255, 255);
    int xx = 0, yy = 260;
    for (int i = 0; i < size - 1; i++)
    {
        // SDL_RenderDrawLine(gRenderer, (i*2), 260, (i*2), 300);
        // SDL_RenderDrawLine(gRenderer, i*2, 260, (i*2+scale), 260);
        // SDL_RenderDrawLine(gRenderer, scale+(i*2), 260, scale+(i*2), 300);
        // SDL_RenderDrawLine(gRenderer, scale+(i*2), 300, scale+(i*2+scale), 300);
        if (test[i] == 0)
        {
            SDL_RenderDrawLine(gRenderer, xx, 280, (xx) + (scale / 2), 280);
            xx = xx + (scale / 2);
            SDL_RenderDrawLine(gRenderer, (xx), 280, (xx), 320);
            SDL_RenderDrawLine(gRenderer, (xx), 320, (xx + (scale / 2)), 320);
            xx = xx + (scale / 2);
        }
        else
        {
            SDL_RenderDrawLine(gRenderer, (xx), 320, (xx + (scale / 2)), 320);
            xx = xx + (scale / 2);
            SDL_RenderDrawLine(gRenderer, (xx), 320, (xx), 280);
            SDL_RenderDrawLine(gRenderer, (xx), 280, (xx + (scale / 2)), 280);
            xx = xx + (scale / 2);
        }

        if (test[i + 1] == test[i])
        {
            SDL_RenderDrawLine(gRenderer, (xx), 280, (xx), 320);
        }
    }

    if (test[size - 1] == 1)
    {
        SDL_RenderDrawLine(gRenderer, (xx), 320, (xx + (scale / 2)), 320);
        xx = xx + (scale / 2);
        SDL_RenderDrawLine(gRenderer, (xx), 320, (xx), 280);
        SDL_RenderDrawLine(gRenderer, (xx), 280, (xx + (scale / 2)), 280);
    }
    else
    {
        SDL_RenderDrawLine(gRenderer, xx, 280, (xx) + (scale / 2), 280);
        xx = xx + (scale / 2);
        SDL_RenderDrawLine(gRenderer, (xx), 280, (xx), 320);
        SDL_RenderDrawLine(gRenderer, (xx), 320, (xx + (scale / 2)), 320);
    }
}

void diff_manchester(int *test, int size, SDL_Renderer *gRenderer, int scale)
{
    SDL_SetRenderDrawColor(gRenderer, 255, 255, 255, 255);
    // SDL_RenderDrawLine(gRenderer, 0, 300, 800, 300);
    SDL_SetRenderDrawColor(gRenderer, 0, 0, 255, 255);
    int xx = 0, yy = 260;
    bool change = false;
    // std::vector<int>y(260,300);
    int y;
    for (int i = 0; i < size - 1; i++)
    {
        y = change ? 320 : 280;
        // SDL_RenderDrawLine(gRenderer, (i*2), 260, (i*2), 300);
        // SDL_RenderDrawLine(gRenderer, i*2, 260, (i*2+scale), 260);
        // SDL_RenderDrawLine(gRenderer, scale+(i*2), 260, scale+(i*2), 300);
        // SDL_RenderDrawLine(gRenderer, scale+(i*2), 300, scale+(i*2+scale), 300);

        SDL_RenderDrawLine(gRenderer, xx, y, (xx) + (scale / 2), y);
        xx = xx + (scale / 2);
        SDL_RenderDrawLine(gRenderer, (xx), 280, (xx), 320);
        if (y == 320)
        {
            y = 280;
        }
        else
        {
            y = 320;
        }
        SDL_RenderDrawLine(gRenderer, (xx), y, (xx + (scale / 2)), y);
        xx = xx + (scale / 2);

        if (test[i + 1] == 0)
        {
            SDL_RenderDrawLine(gRenderer, (xx), 280, (xx), 320);
        }
        else
        {
            change = !change;
        }
    }
    y = change ? 320 : 280;
    if (test[size - 1] == 1)
    {
        SDL_RenderDrawLine(gRenderer, (xx), y, (xx + scale), y);
    }
    else
    {
        SDL_RenderDrawLine(gRenderer, xx, y, (xx) + scale, y);
    }
}

void AlternateMarkInversion(int *test, int size, SDL_Renderer *gRenderer, int scale)
{
    SDL_SetRenderDrawColor(gRenderer, 255, 255, 255, 255);
    // SDL_RenderDrawLine(gRenderer, 0, 300, 800, 300);
    SDL_SetRenderDrawColor(gRenderer, 0, 0, 255, 255);
    bool change = false;
    int xx = 0, yy = 260;
    int y = change ? 320 : 280;
    for (int i = 0; i < size - 1; i++)
    {
        // SDL_RenderDrawLine(gRenderer, (i*2), 260, (i*2), 300);
        // SDL_RenderDrawLine(gRenderer, i*2, 260, (i*2+scale), 260);
        // SDL_RenderDrawLine(gRenderer, scale+(i*2), 260, scale+(i*2), 300);
        // SDL_RenderDrawLine(gRenderer, scale+(i*2), 300, scale+(i*2+scale), 300);
        int y = change ? 320 : 280;

        // if(test[i] == 2){
        // //    test[i] = 1;
        // }

        if (test[i] == 0)
        {
            SDL_RenderDrawLine(gRenderer, xx, 300, (xx) + scale, 300);
            xx = xx + scale;
        }
        else
        {
            SDL_RenderDrawLine(gRenderer, (xx), y, (xx + scale), y);
            xx = xx + scale;
            change = !change;
        }

        if (test[i] == 1)
        {
            SDL_RenderDrawLine(gRenderer, (xx), 300, (xx), y);
        }
        if (test[i] == 2)
        {
            SDL_RenderDrawLine(gRenderer, (xx), 300, (xx), y);
        }

        if (test[i + 1] == 1)
        {
            y = change ? 320 : 280;
            SDL_RenderDrawLine(gRenderer, (xx), 300, (xx), y);
        }
        if (test[i + 1] == 2)
        {
            change = !change;
            y = change ? 320 : 280;
            SDL_RenderDrawLine(gRenderer, (xx), 300, (xx), y);
        }
    }

    y = change ? 320 : 280;

    if (test[size - 1] == 1)
    {
        SDL_RenderDrawLine(gRenderer, (xx), y, (xx + scale), y);
        xx = xx + scale;
        SDL_RenderDrawLine(gRenderer, (xx), 300, (xx), y);
    }
    else
    {
        SDL_RenderDrawLine(gRenderer, xx, 300, (xx) + scale, 300);
    }
}

// the above scramble-Encoding-signal logic is incorrect implement the correct logic here
void Scramble_AMI(int *test, int size, SDL_Renderer *gRenderer, int scale)
{
    SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, 255);
    // SDL_RenderDrawLine(gRenderer, 0, 300, 800, 300);
    SDL_SetRenderDrawColor(gRenderer, 0, 0, 255, 255);
    bool change = false;
    int xx = 0, yy = 260;
    int y = change ? 320 : 280;
    for (int i = 0; i < size - 1; i++)
    {
        // SDL_RenderDrawLine(gRenderer, (i*2), 260, (i*2), 300);
        // SDL_RenderDrawLine(gRenderer, i*2, 260, (i*2+scale), 260);
        // SDL_RenderDrawLine(gRenderer, scale+(i*2), 260, scale+(i*2), 300);
        // SDL_RenderDrawLine(gRenderer, scale+(i*2), 300, scale+(i*2+scale), 300);
        int y = change ? 320 : 280;

        // if(test[i] == 2){
        // //    test[i] = 1;
        // }

        if (test[i] == 0)
        {
            SDL_RenderDrawLine(gRenderer, xx, 300, (xx) + scale, 300);
            xx = xx + scale;
        }
        else
        {
            SDL_RenderDrawLine(gRenderer, (xx), y, (xx + scale), y);
            xx = xx + scale;
            change = !change;
        }

        if (test[i] == 1)
        {
            SDL_RenderDrawLine(gRenderer, (xx), 300, (xx), y);
        }
        if (test[i] == 2)
        {
            SDL_RenderDrawLine(gRenderer, (xx), 300, (xx), y);
        }

        if (test[i + 1] == 1)
        {
            y = change ? 320 : 280;
            SDL_RenderDrawLine(gRenderer, (xx), 300, (xx), y);
        }
        if (test[i + 1] == 2)
        {
            change = !change;
            y = change ? 320 : 280;
            SDL_RenderDrawLine(gRenderer, (xx), 300, (xx), y);
        }
    }

    y = change ? 320 : 280;

    if (test[size - 1] == 1)
    {
        SDL_RenderDrawLine(gRenderer, (xx), y, (xx + scale), y);
        xx = xx + scale;
        SDL_RenderDrawLine(gRenderer, (xx), 300, (xx), y);
    }
    else if (test[size - 1] == 0)
    {
        SDL_RenderDrawLine(gRenderer, xx, 300, (xx) + scale, 300);
    }
    else
    {
        SDL_RenderDrawLine(gRenderer, xx, y, (xx) + scale, y);
    }
}

// ---------------ANALOG----------------
const double PI = 3.141592653589793238462643383279502884;
const float SAMPLE_RATE = 0.125;
// functions in analog
// Function to generate a sine wave
double sine_wave(double frequency, double amplitude, double time)
{
    return amplitude * sin(-2 * PI * frequency * time);
}

// Function to generate a cosine wave
double cosine_wave(double frequency, double amplitude, double time)
{
    return -1 * amplitude * cos(2 * PI * frequency * time);
}

// Function to generate a triangle wave
double triangle_wave(double frequency, double amplitude, double time)
{
    return (2 / PI) * asin(sin(-2 * PI * frequency * time)) * amplitude;
}






std::string A2D(std::unordered_map<int, std ::string> map, std::vector<int> arr)
{
    std::cout << arr.size() << std::endl;
    std::string str;
    for (int i = 0; i < arr.size(); i++)
    {
        str += map[arr[i]];
    }
    // std::cout << str << std::endl;
    return str;
}

void Quantization(int y, std::vector<int> &arr)
{
    y = y / 10;
    y = round(y) * 10;
    arr.push_back(y);
    std::cout << y << std::endl;
}

std:: string SamplingWave(std::unordered_map<int, std ::string> map)
{
    std::vector<int> arr;
    for (float i = SAMPLE_RATE; i < 8; i += SAMPLE_RATE)
    {
        double y = sine_wave(1, 40, i);
        if (y > 5 || y < -5)
        {
            Quantization(y, arr);
        }
    }
    std :: string s1= A2D(map, arr);
    return s1;
}

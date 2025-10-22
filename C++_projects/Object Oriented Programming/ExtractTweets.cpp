//Ali Raza
//24L-0857
//BCS-2D
//Homework # 2
#include<iostream>
using namespace std;
void extract(char**& d, char t[][100], const int& size, int& n) 
{//Extract distinct hashtage first count then check distinct hashtage then create dynamic array of count +1 size and after 
//after storing distinct hashtage in dynamic array store null character at the end of each row 
   // Step 1: Count maximum possible number of distinct hashtags.
   int count = 0;
//   Step 2: First pass to count distinct hashtags
   for (int i = 0; i < size; i++)
   {
       int j = 0;
       while (t[i][j] != '\0')   //loop ruunig untill reached at the end of array 
       {
           if (t[i][j] == '#') 
           {  // Find a hashtag
               int start = j + 1;
               int end = start;

               // Find the end of the hashtag (either space or end of string)
               while (t[i][end] != ' ' && t[i][end] != '\0')
               {//counting total words of hashtag
                   end++;
               }

               // Extract the hashtag (excluding '#')
               int len = end - start;//calculate len of word after hashtage
               bool isDuplicate = false;

               // Check if the hashtag is already seen
               for (int x = 0; x < count; x++)
               {
                   int match = 0;
                   for (int y = 0; y < len; y++)
                   {
                       if (d[x][y] == t[i][start + y]) 
                       {
                           match++;  //count both same digits 
                       }
                   }
                   if (match == len)//if both equal then it is not required hashtage
                   {//if match is equal to len of hashtag then we break inner loop because this is not distinct hashtag
                       isDuplicate = true;
                       break;
                   }
               }

               // If the hashtag is not a duplicate, store it in d
               if (!isDuplicate)
               {
                   d[count] = new char[len + 1];//create char array at count index of array of pointer 
                   for (int m = 0; m < len; m++)
                   {
                       d[count][m] = t[i][start + m];
                   }
                   d[count][len] = '\0'; // Null-terminate the string
                   count++;//increment for next hashtage
               }
           }
           j++;
       }
   }

   n = count;  // Set the number of distinct hashtags
}
void print(char**& d, const int& n)//pass paremeter by reference then create alias of parameters
{//printing our dynamic array that stored  distinct hashtags 
   for (int i = 0; i < n; i++)
   {
       for (int j = 0;d[i][j] != '\0';j++)
       {
           cout << d[i][j];
       }
       cout << endl;
   }
   
}
void deallocate(char**& d,const int &n)
{//cleaning memory on heap 
   for (int i = 0; i < n; i++)
   {
       delete[] d[i];
   }
   delete[] d;
   d = nullptr;
}
int main()
{
   const int N = 20;
   char tweets[N][100] = {
       "I love programming!#coding #developer #tech ",
       "Just read a great book about AI!#reading #AI #books ",
       "The weather today is fantastic!#sunny #beautiful ",
       "Had an amazing workout session!#fitness #health #motivation ",
       "Finally, coffee time!#coffee #morning #energy ",
       "Learning C programming!#coding #learning ",
       "Can't wait for the weekend! #weekendvibes #excited ",
       "Enjoying a relaxing day at the beach! #vacation #beach #relax",
       "New project starting today!#work #project #goals ",
       "Running in the park!#fitness #nature ",
       "Loving this tech conference!#tech #developer #AI ",
       "Weekend vibes and relaxation time!#weekendvibes #vacation #relax ",
       "Fitness goals achieved today!#fitness #health #motivation ",
       "Finally got my first coffee today!#coffee #morning #energy ",
       "Building a new app with C!#coding #developer ",
       "Taking a walk at the beach. #beach #vacation #nature ",
       "Just finished an AI course!#AI #learning #tech ",
       "Work is so rewarding today!#work #project #goals ",
       "A morning walk to clear my mind!#morning #fitness #nature ",
       "Amazing sunny day!#sunny #beautiful #weekendvibes "};
   char** data = new char* [100];  // Allocate enough space for up to 100 distinct hashtags
   int n = 0;//for size of row dynamic array 2D array 
   extract(data, tweets, N, n);//pass parameters  for extract hashtags
   print(data, n);//display dynamic array of hashtages
   deallocate(data,n);//releasing memory and free our pointer to reallocate any other memory
   
}

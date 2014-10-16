//
//  main.cpp
//  btp
//
//  Created by Mario Loera Lozano on 9/8/14.
//  Copyright (c) 2014 kth. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

//direction of the map
int xo=1,yo=1,xp,yp,X,Y,lookfor,Z;

int xWinOdd,yWinOdd,xWinEven,yWinEven;

//size of the map
int  numRow,numColumns;

//varialbe for minimun conditions to play
int goal=0,player=0,playeringoal=0;

bool searchDone, update, find,evenNum,win=false;
std::string solution;

//std::vector<std::int8_t> board2;

//std::vector<int> board4;


std::vector<std::string> vector;
//std::vector<std::vector<int> > boardInt2(numRow, std::vector<int>(numColumns));
std::vector<std::vector<int> > boardInt2;


//********************function declaration*****************
std::vector<std::string> readBoard(std::vector<std::string>); //copy the board into copyboard
std::vector<std::vector<int> > makemap2d(std::vector<std::string>); //copy the board into copyboard
void printmap2d();

void searchfuntion ();
void maskUpadate ();
void maskWin ();





int main(int argc, const char * argv[])
{

    //std::cout<<"START"<<std::endl;
    
    // Read the board
    std::vector<std::string> board;
    for (std::string line; getline(std::cin, line);)
        board.push_back(line);
    
    //function to print the board
    //std::cout<<"PRINT BOARD"<<std::endl;
    
    
    readBoard(board);
    
    
    std::vector<std::vector<int> > boardInt(numRow, std::vector<int>(numColumns));

    
    //funtion to create vecto of vector of interger
    //std::cout<<"boardInt2=makemap2d(board);"<<std::endl;
    
    
    boardInt2=makemap2d(board);
    
    
    //call sear funtion just for printing the update after the mask
    //printmap2d();
    
    //mimimum conditions to play
    
    
    if(playeringoal>0)//play in gool win
    {
        std::cout << ""<<std::endl;
        return 0;
    }
    if(goal==0)//no goarl found
    {
        std::cout << "no path"<<std::endl;
        return 0;
    }
    if(player==0)//no player found
    {
        std::cout << "no path"<<std::endl;
        return 0;
    }
    
    //ciclo de busqueda > mascara > update.
    
    //std::cout <<"search - maskUpdate -print FUNCTION"<<std::endl;
    
    lookfor=2;
    update=true;
    find=true;
    //std::cout <<numColumns<<" " <<numRow<<std::endl;
    
    
    //initial contition for every look for
    
    while(find&&update)
    {
        find=false;
        update=false;
        xo=0;
        yo=0;
        update=false;
        searchDone=false;
        
    
        while(!searchDone)
            {
          
                //std::cout <<"while lookfor="<<lookfor<<std::endl;
                searchfuntion();
                maskUpadate ();
                if(win)
                    break;
            
            }
        if(win)
        {
            
            break;
        }
        
        lookfor=lookfor+2 ;
        //searchfuntion();
        
        //std::cout <<"new look for" <<lookfor<<std::endl;
        
            //if(!update)//after the serar is donde and no update.
            //lookfor++;
        

    }
    
    if(find && !win)
        std::cout <<"no path" <<std::endl;
    
    if(win)
    {
        
        
        //std::cout<<"XW even "<<xWinEven<<" YW even "<<yWinEven <<std::endl;
        //std::cout<<"XW odd "<<xWinOdd<<" YW odd "<<yWinOdd <<std::endl;
        //std::cout<<"solution="<<solution<<std::endl;
        //printmap2d();
        
     
        
        
        //std::cout<<"odd value"<<boardInt2[yp][xp]<<std::endl;
        //std::cout<<"xp "<<xp<<". yp "<<yp<<std::endl;
        
        
        //start loop function maskwin with odd number.
        xp=xWinOdd;
        yp=yWinOdd;
      
                while(boardInt2[yp][xp] !=1)
                    
                {
                   // std::cout <<" ERROR 6"<<std::endl;

                    maskWin();
                    //std::cout<<"z "<<Z<<". lookfor "<<lookfor<<std::endl;
                }
        
        
        
    
        
        //start loop function maskwin with even number.

        xp=xWinEven;
        yp=yWinEven;
        
        while(boardInt2[yp][xp] !=2)
        {
            maskWin();
        }
        //printmap2d();
        std::cout <<solution << std::endl;
        
    }
    
    

    
    
    
    
    
    return 0;//return main
}//close main

//**************************FUNCTIONS DEFINITION**************************
//get copyboard, get information numRow numColumsn
std::vector<std::string> readBoard(std::vector<std::string> vector)
{
    //find the number of rows
    numRow=vector.size();
    numColumns=0;
    //Reprint the board and get the number of columns
    for(Y=0;Y<vector.size();Y++)
    {
        //print every row
        //std::cout << vector[Y] << std::endl;
        
        //number or colums per row
        //std::cout << board[X].size() <<std::endl;
        //keep the higest number of columns
        if(vector[Y].size()>numColumns)
        {
            numColumns = vector[Y].size();
        }
        
    }
    
    //remove the margins
    numColumns--;
    numRow--;
    return vector;
    
}// cloe getboar2

//get makemap2d
std::vector<std::vector<int> > makemap2d(std::vector<std::string> vector)
{
    std::vector<std::vector<int> > boardInt(numRow, std::vector<int>(numColumns));
    //std::vector<std::vector<int> > boardInt2(numRow, std::vector<int>(numColumns));

    //starts in [1][1] to avoid the first ones
    for(Y=1;Y<numRow;Y++)
    {
        for (X=1;X<numColumns;X++)
        {
            //box, wall, box in goal
            if (vector[Y][X]=='#' ||vector[Y][X]=='*' ||vector[Y][X]=='$')
            {
                //std::cout << "EROR*******" << std::endl << std::endl;
                boardInt[Y-1][X-1]=-1;
                //display every element of the first row
                //std::cout << " "<< boardInt[X-1][Y-1];
            }
            
            //empty spaces & shorter columns
            if (vector[Y][X]==' ' || vector[Y][X]==0)
            {
                boardInt[Y-1][X-1]=0;
                //display every element of the first row
                //std::cout << "  " <<boardInt[X-1][Y-1];
            }
            
            //player
            if (vector[Y][X]=='@')
            {
                boardInt[Y-1][X-1]=2;
                //display every element of the first row
                //std::cout << "  " <<boardInt[X-1][Y-1];
                player++;
            }
            
            //goal
            if (vector[Y][X]=='.')
            {
                boardInt[Y-1][X-1]=1;
                //display every element of the first row
                //std::cout << "  " <<boardInt[X-1][Y-1];
                goal++;
            }
            
            //player in goal
            if (vector[Y][X]=='+')
            {
                boardInt[Y-1][X-1]=3;
                //display every element of the first row
                //std::cout << "  " <<boardInt[X-1][Y-1];
                playeringoal++;
            }
            
        }
        //move to the next row
        //std::cout << std::endl;
        
    }
    numColumns--;
    numRow--;
    boardInt2=boardInt;
    return boardInt2 ;
}//close int makemap2d

// print map2d
void printmap2d()
{
    for(Y=0;Y<numRow;Y++)
    {
        for (X=0;X<numColumns;X++)
        {
            //printing in good order until 4 digits number
            
            
            if(boardInt2[Y][X]<10 && boardInt2[Y][X]>=0)  //one digit 0:9
                std::cout << "   "<<boardInt2[Y][X];
            else if (boardInt2[Y][X]<100 || boardInt2[Y][X]<0) //2 digits -1 10:99
                std::cout << "  "<< boardInt2[Y][X];
            else if (boardInt2[Y][X]<1000) //3 digits
                std::cout << " "<< boardInt2[Y][X];
            else //4 digits
                std::cout << ""<< boardInt2[Y][X];
            //******result from the sear
            
        }
        //move to the next row
        std::cout << std::endl;
        
    }
    return;
}//close printmap2d

//get search funtion
void searchfuntion ()
{

 for(Y=yo;Y<numRow;Y++)
 {
     for (X=xo;X<numColumns;X++)
     {
         if (boardInt2[Y][X]==lookfor)//search
         {
             xp=X;
             yp=Y;
             find=true;
             
             
             //std::cout<<"xp = "<< xp  << ", yp = "<< yp<<", value of boardInt2[xp][yp] = " << boardInt2[Y][X]<<std::endl;
            
            
             
             //assign [yo][xo] to the next possition for continue the search
             if((xp+1)<numColumns)//xp is not the last one increase
             {
                 xo=xp+1;
                 yo=yp;
                 return;// exit the function once the lookfor was found, but the search is not done
             }
             else//xp is the last one , restart
             {
                 xo=0;
                 if((yp+1)<numRow)//if yp is not the last one increase
                 {
                  yo=yp+1;
                  return;// exit the function once the lookfor was found, but the search is not done
                 }
             
                 else// yp is the last one, restar
                 {
                     yo=0;
                     break;//break to avoid to be in the for loop again and search is Done
                 }
             }
         }
     }//for X
     xo=0;
 }//for Y
searchDone=true;
return;
}//close searchfunction

//mask upadate funtion
void maskUpadate ()
{
   
    
    //std::cout<<"xp="<<xp<<". yp="<<yp<<". maks update \n";
    //std::cout<<"xo = "<< xo  << ", yo = "<< yo<<std::endl;
    
    
    
    if((xp-1)>=0)//  check the left limit in the boardInt2
    {
       
   
        if(boardInt2[yp][xp-1]>0)//posible to update or win
        {
            if(boardInt2[yp][xp-1]%2^lookfor%2)//one is odd and the other is even number
            {
                win=true;
                if(lookfor%2==0)//from start to goal natural movement
                {
                    solution="L";
                    xWinEven=xp;
                    xWinOdd=xp-1;
                    //
                }
                else//from goal to start, reverse the movement
                {
                    solution="R";
                    xWinEven=xp-1;
                    xWinOdd=xp;
                    //
                }
                yWinEven=yp;
                yWinOdd=yp;
                //std::cout <<"WIN 1 "<<solution<<std::endl;
                //printmap2d();
                //std::cout<<"xp = "<< xp  << ", yp = "<< yp<<", value of boardInt2[xp][yp] = " << boardInt2[yp][xp]<<std::endl;
                return;
            }
        }
        
            if(boardInt2[yp][xp-1]==0)//update the number if is not been visited
            {
                boardInt2[yp][xp-1]=lookfor+2;
                update=true;
            }
    }
    
    
    
    if((xp+1)<numColumns)//check in right
    {
        //std::cout <<"if((xp+1)<numColumns)"<<std::endl;
        
       if(boardInt2[yp][xp+1]>0)
       {
            if(boardInt2[yp][xp+1]%2^lookfor%2)//win
            {
                win=true;
                if(lookfor%2==0)//from start to goal natural movement
                {
                    solution="R";
                    xWinEven=xp;
                    xWinOdd=xp+1;
                    

                    //
                }
                else//from goal to start, reverse the movement
                {
                    solution="L";
                    xWinEven=xp+1;
                    xWinOdd=xp;
                    
                    //
                }
                yWinEven=yp;
                yWinOdd=yp;

                //std::cout <<"WIN 2 "<<solution<<std::endl;
                //printmap2d();
                //std::cout<<"xp = "<< xp  << ", yp = "<< yp<<", value of boardInt2[xp][yp] = " << boardInt2[yp][xp]<<std::endl;
                return;
            }
       }
        
            if(boardInt2[yp][xp+1]==0)//update
            {
                boardInt2[yp][xp+1]=lookfor+2;
                update=true;
            }
       
    }
    
    
    //std::cout<<"xp = "<< xp  << ", yp = "<< yp<<", value of boardInt2[xp][yp] = " << boardInt2[yp][xp]<<std::endl;
    //std::cout<<" lookfor = " << lookfor<<std::endl;
    if((yp-1)>=0)//check up
    {
        //std::cout <<" if((yp-1)>=0)"<<std::endl;
        
        if(boardInt2[yp-1][xp]>0)
        {
        
            if(boardInt2[yp-1][xp]%2^lookfor%2)
            {
                //std::cout<<" boardInt2[yp-1][xp]= " << boardInt2[yp-1][xp]<<std::endl;

                win=true;
                if(lookfor%2==0)//from start to goal natural movement
                {
                    solution="U";
                    yWinEven=yp;
                    yWinOdd=yp-1;
                    
                    
                    //
                }
                else//from goal to start, reverse the movement
                {
                    solution="D";
                    yWinEven=yp-1;
                    yWinOdd=yp;

                    //
                }
                xWinEven=xp;
                xWinOdd=xp;
                //std::cout <<"WIN 3 "<<solution<<std::endl;
                //printmap2d();
                //std::cout<<"xp = "<< xp  << ", yp = "<< yp<<", value of boardInt2[xp][yp] = " << boardInt2[yp][xp]<<std::endl;
                return;
            }

        }
            
            if(boardInt2[yp-1][xp]==0)
            {
                boardInt2[yp-1][xp]=lookfor+2;
                update=true;
            }
        
        
    }
    
    
    
    if((yp+1)<numRow)//check down
    {
        //std::cout <<"if((yp+1)<numRow)"<<std::endl;
        if(boardInt2[yp+1][xp]>0)
        {
        
            if(boardInt2[yp+1][xp]%2^lookfor%2)//
            {
                win=true;
                if(lookfor%2==0)//from start to goal natural movement
                {
                    solution="D";
                    yWinEven=yp;
                    yWinOdd=yp+1;
                    //
                }
                else//from goal to start, reverse the movement
                {
                    solution="U";
                    yWinEven=yp+1;
                    yWinOdd=yp;
                    
                    //
                }
                xWinEven=xp;
                xWinOdd=xp;
                //std::cout <<"WIN 4 "<<solution<<std::endl;
                //printmap2d();
                //std::cout<<"xp = "<< xp  << ", yp = "<< yp<<", value of boardInt2[xp][yp] = " << boardInt2[yp][xp]<<std::endl;
                return;
            }
        }
        
            if(boardInt2[yp+1][xp]==0)
            {
                boardInt2[yp+1][xp]=lookfor+2;
                update=true;
            }
        
    }
    
    

    
}//close maskUpdate

//mask upadate funtion
void maskWin ()
{
    Z=boardInt2[yp][xp];
    
    if((xp-1)>=0)//  check the left limit in the boardInt2
    {
        
        lookfor=boardInt2[yp][xp-1];
        if(lookfor>0 && Z>lookfor)// a number higher than zero and lower thant the curretn state
        {
            
            if((lookfor+Z)%2==0)// both odd or both even
            {
                //printf("1 ");
                if(Z%2==0)//from match to start //inverse
                {
                    solution="R "+solution;
                    //printf("R ");
                }
                else//from match to goal //natural
                {
                    solution=solution+" L";
                    //printf("L ");
                }
                xp--;

                return;
            }
        }
        
    }
    
    if((xp+1)<numColumns)//check in right
    {
        lookfor=boardInt2[yp][xp+1];
        
        if(lookfor>0 && Z>lookfor)// a number higher than zero and lower thant the curretn state
        {
            
            if((lookfor+Z)%2==0)// both odd or both even
            {
                //printf("2 ");
                if(Z%2==0)// both odd or both even
                {
                    solution="L "+solution;
                    //printf("L ");
                }
                else//from goal to start, reverse the movement
                {
                    solution=solution+" R";
                    //printf("R ");
                }
                xp++;
                return;
            }
        }
        
    }
    
    if((yp-1)>=0)//check up
    {
        lookfor=boardInt2[yp-1][xp];

        
         if(lookfor>0 && Z>lookfor)// a number higher than zero and lower thant the curretn state
        {
            
            if((lookfor+Z)%2==0)// both odd or both even
            {
                //printf("3 ");
                if(lookfor%2==0)//from start to goal natural movement
                {
                    solution="D "+solution;
                    //printf("D ");
                }
                else//from goal to start, reverse the movement
                {
                    solution=solution+" U";
                    //printf("U ");
                }
                yp--;
                return;
            }
            
        }
    }
    
    if((yp+1)<numRow)//check down
    {
         lookfor=boardInt2[yp+1][xp];
        if(lookfor>0 && Z>lookfor)// a number higher than zero and lower thant the curretn state
        {
           
            if((lookfor+Z)%2==0)// both odd or both even
            {
                //printf("4 ");
                if(lookfor%2==0)//from start to goal natural movement
                {
                    solution="U "+solution;
                    //printf("U ");
                }
                else//from goal to start, reverse the movement
                {
                    solution=solution+" D";
                    //printf("D ");
                }
                yp++;
                return;
            }
        }

        
    }
    return;
}//close maskWin




//  boild.h
//  Created by Mario Loera Lozano on 10/20/14.
//  Copyright (c) 2014 kth. All rights reserved.

#ifndef test_boild_h
#define test_boild_h
    //cretete text file for parametes
    void write_parameters(){
        printf("creat file parameters_boids.txt\n ");
        FILE *fw = NULL;
        fw = fopen("parameters_boids.txt", "w");
        /////////////////CREATE A FILE/////////////////
        fprintf(fw, "k_centre = 0.0001\nk_repulsion = 0.5\nk_cohesion = 0.00025\nk_target = 0.005\nV_MAX = 45.0\nREPULSION_DISTANCE = 30.0");
        fclose(fw);
        return;
    }

    //update parameters from text file
    double * read_parameters(){
        static double parameters[6];//static point to store the parameter and acces with pointer
        //* param    = k_centre
        //* (param+1)= k_repulsion
        //* (param+2)= k_cohesion
        //* (param+3)= k_target
        //* (param+4)= V_MAX
        //* (param+5)= REPULSION_DISTANCE
        /////////////////READ A FILE/////////////////
        FILE *fr = NULL;
        fr = fopen("parameters_boids.txt", "r");
        fscanf(fr, "k_centre = %lf\nk_repulsion = %lf\nk_cohesion = %lf\nk_target = %lf\nV_MAX = %lf\nREPULSION_DISTANCE = %lf",&parameters[0],&parameters[1],&parameters[2],&parameters[3],&parameters[4],&parameters[5]);
        fclose(fr);
        //printf("I read parameters: %lf %lf %lf %lf %lf %lf \n",parameters[0],parameters[1],parameters[2],parameters[3],parameters[4],parameters[5]);
        return &parameters[0];//return a point to the first element of the array
    }

    //clamp functions
        int clamp_int(int value, int low, int high){
            return value < low ? low : (value > high ? high : value);
        }
        double clamp_double(double value, double low, double high){
            return value < low ? low : (value > high ? high : value);
        }

    //delay funtion
    void delay(int max){
        max=clamp_int(max,1,5);
        long int i;
        for (i=0;i<100000000*max;i++){//printf("\ni=%d\n",i);
        }
        return;
    }

    //structure for storage the the boild[N];
    struct position{
        double x;
        double y;
        double z;
    };

    struct velocity{
        double x;
        double y;
        double z;
        
    };
    struct boid{
        struct position pos;
        struct velocity vel;
    };

    struct boid b[10];//array of boild
    struct boid *bp=&b[0];//pointer to acces the array


//    void print_pointer(struct boild *local){
//        printf("b[2].vel.y=89 = %f\n",local[2].vel.y);
//        return;
//    }

//    void update_pointer(struct boild *local,double a){
//        local[2].vel.y=a;
//        return;
//    }


#endif

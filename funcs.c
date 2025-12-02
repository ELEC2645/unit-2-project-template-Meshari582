//gcc main.c funcs.c -lm -o main.out
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <math.h>
#include "funcs.h"


/////////////////////////////////Test menu//////////////////////////
void menu_test(void) {
    printf("\nMenu successful\n");
   
}
////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////Buck menu 1////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
void menu_item_1(void) {
    printf("\n----------- Buck converter -----------\n");
    printf("\nSelect the wanted unknowns"
           "\t\t\t\t\t\t\n"
           "\t1. Find K\t\t\n"
           "\t2. Find Vi/Vo\t\t\n"
           "\t3. Back to main menu\t\t\t\t\n"
           "\t\t\t\t\t\t\n");
    printf("---------------------------------------------\n");
    //printf("Enter first number: \n");
    int num1;

    int er1=ask_number(&num1);
    if (er1 == -2){
        printf("\nInvalid input!");
        go_back_to_main();
    }
    int input=num1;
    void select_menu_item(int input); {
    switch (input) {
        case 1: menu2_item_1(); break; //Find K
        case 2: menu6_item_1(); break; //Find Vi/Vo
        case 3: printf("Back to main menu\n"); go_back_to_main();
        default: printf("Invalid selection. Exiting...\n"); exit(1);
    }
}
 

}

//////////////////////////Boost menu 1///////////////////////
void menu_item_2(void) {
    printf("\ncoming in update 2.2.3.4.5.3.2.12.1.2.3.46.8.7.65.43.3");
    go_back_to_main();


}

/////////////////////////Calculating IOB MAX (Vi/Vo constant)////////////////////////////////
void IOBMAX_CVI_BUCK(float vi ,float L, float ts, float *iobmax){
    *iobmax= (vi * ts)/(8.0f * L);
}
void IOBMAX_CVO_BUCK(float vo ,float L, float ts, float *iobmax){
    *iobmax= (vo * ts)/(2.0f * L);
}

///////////////////Calculating IOB MAX (Vi/Vo constant) (given K)////////////////////////////////
void IOBMAX_CVI_BUCK_K(float vi ,float L, float ts,float K, float *iobmax){
    *iobmax= ((vi * ts)/(2.0f * L))*(K*(1.0f-K));
}
void IOBMAX_CVO_BUCK_K(float vo ,float L, float ts, float K, float *iobmax){
    *iobmax= ((vo * ts)/(2.0f * L))*(1.0f-K);
}

/////////////////////////////////////////////////////////////////////
//////////////////////////////////Buck menu 2////////////////////////
//////////////////////////////////////////////////////////////////////

void menu2_item_1(void) { //The first menu for finding K
    printf("\n----------- Buck converter -----------\n");
    printf("\nSelect the given variables"
           "\t\t\t\t\t\t\n"
           "\t1. Io\t\t\n"
           "\t2. Po/Pi, constant Vo\t\t\n"
           "\t3. Delta IL, IL peak\t\t\t\t\n"
           "\t4. Delta IL, IL min\t\t\t\t\n"
           "\t5. Back to main menu\t\t\t\t\n"
           "\t\t\t\t\t\t\n");
    printf("---------------------------------------------\n");
    //printf("Enter first number: \n");
    int num200;

    int er1=ask_number(&num200);
    if (er1 == -2){
        printf("\nInvalid input!");
        go_back_to_main();
    }
    int input=num200;
    void select_menu_item(int input); {
    switch (input) {
        case 1: menu3_item_1(); break;  //IO given, straight to Vi/Vo menu
        case 2: menu3_item_2(); break;  //Po/Pi + Vo 
        case 3: menu3_item_3(); break;  //Delta IL, ILpeak
        case 4: menu3_item_4(); break;  //Delta IL, ILmin
        case 5: printf("Back to main menu\n"); go_back_to_main();
        default: printf("Invalid selection. Exiting...\n"); exit(1);
    }
}
}


//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////Constant Vo/Vi function definitions ///////////////////
//////////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////constant vi///////////////////////////////
void menu3_item_Vi(float IO) {
    printf("\nInput Vi\n");
    float vi;
    int er2015=ask_numberf(&vi);
    if (er2015 == -2){
       printf("\nInvalid input!");
      go_back_to_main();
    }
    printf("\nInput L\n");
    float L;
    int er2016=ask_numberf(&L);
    if (er2016 == -2){
       printf("\nInvalid input!");
      go_back_to_main();
    }
    if (L == 0){
        printf("\n L cannot =0, division by 0!");
        go_back_to_main();
    }
    printf("\nInput Ts\n");
    float ts;
    int er2017=ask_numberf(&ts);
    if (er2017 == -2){
       printf("\nInvalid input!");
      go_back_to_main();
    }
    if (ts == 0){
        printf("\n Ts cannot =0, division by 0!");
        go_back_to_main();
    }
    float IOB_MAX;
    IOBMAX_CVI_BUCK(vi, L, ts, &IOB_MAX);
    printf("IOBMAX = %f", IOB_MAX);

    if (IO>IOB_MAX){ //CCM
           printf("\n----------- Buck converter -----------\n");
    printf("\nConver operates in CCM\n"
            "\nSelect the given variables:\n"
           "\t\t\t\t\t\t\n"
           "\t1. Ii\t\t\n"
           "\t2. Ts\t\t\n"
           "\t3. Desired Vo\t\t\n"
           "\t4. Go back to main menu\t\t\t\t\n"
           "\t\t\t\t\t\t\n");
    printf("---------------------------------------------\n");
    int num3005;

    int er1=ask_number(&num3005);
    if (er1 == -2){
        printf("\nInvalid input!");
        go_back_to_main();
    }
    int input=num3005;
    switch (input) {
        case 1: menu4_item_1(IO); break;  //menu 4 item 1 Ii
        case 2: menu4_item_2(ts); break;  //menu 4 item 2 Ts
        case 3: menu4_item_3(vi); break;  //menu 3 item 3 Vo
        case 4: printf("Back to main menu\n"); go_back_to_main();
        default: printf("Invalid selection. Exiting...\n"); exit(1);
    }
}
    else  if (IO<IOB_MAX){ //DCM
        printf("\n----------- Buck converter -----------\n");
    printf("\nConver operates in DCM\n"
            "\nInput ideal Vo:\n"
           "\t\t\t\t\t\t\n"
           "\t1. Vo\t\t\n"
           "\t2. Go back to main menu\t\t\t\t\n"
           "\t\t\t\t\t\t\n");
    printf("---------------------------------------------\n");
    int num3006;

    int er7=ask_number(&num3006);
    if (er7 == -2){
        printf("\nInvalid input!");
        go_back_to_main();
    }
    int input=num3006;
    switch (input) {
        case 1: menu5_item_1(IO, IOB_MAX, vi); break;  
        case 2: printf("Back to main menu\n"); go_back_to_main();
        default: printf("Invalid selection. Exiting...\n"); exit(1);
    }
    }
    
}

//////////////////////////////////////////Constat vo////////////////////////////////////////////
void menu3_item_Vo(float IO) {
   printf("\nInput Vo\n");
    float vo;
    int er2015=ask_numberf(&vo);
    if (er2015 == -2){
       printf("\nInvalid input!");
      go_back_to_main();
    }

    printf("\nInput L\n");
    float L;
    int er2016=ask_numberf(&L);
    if (er2016 == -2){
       printf("\nInvalid input!");
      go_back_to_main();
    }
     if (L == 0){
        printf("\n L cannot =0, division by 0!");
        go_back_to_main();
    }
    printf("\nInput Ts\n");
    float ts;
    int er2017=ask_numberf(&ts);
    if (er2017 == -2){
       printf("\nInvalid input!");
      go_back_to_main();
    }
     if (ts == 0){
        printf("\n Ts cannot =0, division by 0!");
        go_back_to_main();
    }
    float IOB_MAX;
    IOBMAX_CVO_BUCK(vo ,L, ts, &IOB_MAX);
    printf("IOBMAX = %f", IOB_MAX);
    
        if (IO>IOB_MAX){ //CCM
           printf("\n----------- Buck converter -----------\n");
    printf("\nConver operates in CCM\n"
            "\nSelect the given variables:\n"
           "\t\t\t\t\t\t\n"
           "\t1. delta i\t\t\n"
           "\t2. Co\t\t\n"
           "\t3. Desired Vi\t\t\n"
           "\t4. Go back to main menu\t\t\t\t\n"
           "\t\t\t\t\t\t\n");
    printf("---------------------------------------------\n");
    int num3005;

    int er1=ask_number(&num3005);
    if (er1 == -2){
        printf("\nInvalid input!");
        go_back_to_main();
    }
    int input=num3005;
    switch (input) {
        case 1: menu4_item_4(ts,vo,L); break;       //delta i,
        case 2: menu4_item_5(ts, vo, L); break;     //co
        case 3: menu4_item_6(vo); break;            //desired vi
        case 4: printf("Back to main menu\n"); go_back_to_main();
        default: printf("Invalid selection. Exiting...\n"); exit(1);
    }
}
    else  if (IO<IOB_MAX){ //DCM
        printf("\n----------- Buck converter -----------\n");
    printf("\nConver operates in DCM\n"
            "\nInput ideal Vi:\n"
           "\t\t\t\t\t\t\n"
           "\t1. Vo\t\t\n"
           "\t2. Go back to main menu\t\t\t\t\n"
           "\t\t\t\t\t\t\n");
    printf("---------------------------------------------\n");
    int num3006;

    int er7=ask_number(&num3006);
    if (er7 == -2){
        printf("\nInvalid input!");
        go_back_to_main();
    }
    int input=num3006;
    switch (input) {
        case 1: menu5_item_2(IO, IOB_MAX, vo); break;  
        case 2: printf("Back to main menu\n"); go_back_to_main();
        default: printf("Invalid selection. Exiting...\n"); exit(1);
    }
    }
    

}
void menu3_item_Vo_given(float IO, float vo) {
   printf("\nVo constant given as %f\n", vo);
    printf("\nInput L\n");
    float L;
    int er2016=ask_numberf(&L);
    if (er2016 == -2){
       printf("\nInvalid input!");
      go_back_to_main();
    }
     if (L == 0){
        printf("\n L cannot =0, division by 0!");
        go_back_to_main();
    }
    printf("\nInput Ts\n");
    float ts;
    int er2017=ask_numberf(&ts);
    if (er2017 == -2){
       printf("\nInvalid input!");
      go_back_to_main();
    }
     if (ts == 0){
        printf("\n Ts cannot =0, division by 0!");
        go_back_to_main();
    }
    float IOB_MAX;
    IOBMAX_CVO_BUCK(vo ,L, ts, &IOB_MAX);
    printf("IOBMAX = %f", IOB_MAX);
    
        if (IO>IOB_MAX){
           printf("\n----------- Buck converter -----------\n");
    printf("\nConver operates in CCM\n"
            "\nSelect the given variables:\n"
           "\t\t\t\t\t\t\n"
           "\t1. delta i\t\t\n"
           "\t2. Co\t\t\n"
           "\t3. Desired Vi\t\t\n"
           "\t4. Go back to main menu\t\t\t\t\n"
           "\t\t\t\t\t\t\n");
    printf("---------------------------------------------\n");
    int num3005;

    int er1=ask_number(&num3005);
    if (er1 == -2){
        printf("\nInvalid input!");
        go_back_to_main();
    }
    int input=num3005;
    switch (input) {
        case 1: menu4_item_4(ts,vo,L); break;       //delta i,
        case 2: menu4_item_5(ts, vo, L); break;     //co 
        case 3: menu4_item_6(vo); break;            //desired vi
        case 4: printf("Back to main menu\n"); go_back_to_main();
        default: printf("Invalid selection. Exiting...\n"); exit(1);
    }
}
    else  if (IO<IOB_MAX){
        printf("\n----------- Buck converter -----------\n");
    printf("\nConver operates in DCM\n"
            "\nInput ideal Vi:\n"
           "\t\t\t\t\t\t\n"
           "\t1. Vo\t\t\n"
           "\t2. Go back to main menu\t\t\t\t\n"
           "\t\t\t\t\t\t\n");
    printf("---------------------------------------------\n");
    int num3006;

    int er7=ask_number(&num3006);
    if (er7 == -2){
        printf("\nInvalid input!");
        go_back_to_main();
    }
    int input=num3006;
    switch (input) {
        case 1: menu5_item_2(IO, IOB_MAX, vo); break;  
        case 2: printf("Back to main menu\n"); go_back_to_main();
        default: printf("Invalid selection. Exiting...\n"); exit(1);
    }
    }
    

}

/////////////////////////////////////////cosntant vi (given K)///////////////////////////////////
void menu7_item_Vi(float IO, float K) {
    printf("\nInput Vi\n");
    float vi;
    int er2015=ask_numberf(&vi);
    if (er2015 == -2){
       printf("\nInvalid input!");
      go_back_to_main();
    }
    printf("\nInput L\n");
    float L;
    int er2016=ask_numberf(&L);
    if (er2016 == -2){
       printf("\nInvalid input!");
      go_back_to_main();
    }
     if (L == 0){
        printf("\n L cannot =0, division by 0!");
        go_back_to_main();
    }
    printf("\nInput Ts\n");
    float ts;
    int er2017=ask_numberf(&ts);
    if (er2017 == -2){
       printf("\nInvalid input!");
      go_back_to_main();
    }
     if (ts == 0){
        printf("\n ts cannot =0, division by 0!");
        go_back_to_main();
    }
    float IOB_MAX;
    IOBMAX_CVI_BUCK_K(vi, L, ts, K, &IOB_MAX);
    printf("IOBMAX = %f", IOB_MAX);
    if (IO>IOB_MAX){
           printf("\n----------- Buck converter -----------\n");
    printf("\nConver operates in CCM\n"
            "\nSelect the desired path:\n"
           "\t\t\t\t\t\t\n"
           "\t1. Vo\t\t\n"
           "\t2. Go back to main menu\t\t\t\t\n"
           "\t\t\t\t\t\t\n");
    printf("---------------------------------------------\n");
    int num3005;

    int er1=ask_number(&num3005);
    if (er1 == -2){
        printf("\nInvalid input!");
        go_back_to_main();
    }
    int input=num3005;
    switch (input) {
        case 1: menu8_item_1(K, vi); break;  //vo
        case 2: printf("Back to main menu\n"); go_back_to_main();
        default: printf("Invalid selection. Exiting...\n"); exit(1);
    }
}
    else  if (IO<IOB_MAX){
        printf("\n----------- Buck converter -----------\n");
    printf("\nConver operates in DCM\n"
            "\nSelect desired path:\n"
           "\t\t\t\t\t\t\n"
           "\t1. Vo\t\t\n"
           "\t2. Go back to main menu\t\t\t\t\n"
           "\t\t\t\t\t\t\n");
    printf("---------------------------------------------\n");
    int num3006;

    int er7=ask_number(&num3006);
    if (er7 == -2){
        printf("\nInvalid input!");
        go_back_to_main();
    }
    int input=num3006;
    switch (input) {
        case 1: menu8_item_2(IO, IOB_MAX, vi, K); break;  //menu 4 item 1 Ii
        case 2: printf("Back to main menu\n"); go_back_to_main();
        default: printf("Invalid selection. Exiting...\n"); exit(1);
    }
    
}
}

/////////////////////////////////////////cosntant vo (given K)///////////////////////////////////
void menu7_item_Vo(float IO, float K){
   printf("\nInput Vo\n");
    float vo;
    int er2015=ask_numberf(&vo);
    if (er2015 == -2){
       printf("\nInvalid input!");
      go_back_to_main();
    }
    printf("\nInput L\n");
    float L;
    int er2016=ask_numberf(&L);
    if (er2016 == -2){
       printf("\nInvalid input!");
      go_back_to_main();
    }
     if (L == 0){
        printf("\n L cannot =0, division by 0!");
        go_back_to_main();
    }
    printf("\nInput Ts\n");
    float ts;
    int er2017=ask_numberf(&ts);
    if (er2017 == -2){
       printf("\nInvalid input!");
      go_back_to_main();
    }
     if (ts == 0){
        printf("\n Ts cannot =0, division by 0!");
        go_back_to_main();
    }
    float IOB_MAX;
    IOBMAX_CVO_BUCK_K(vo ,L, ts,K, &IOB_MAX);
    printf("IOBMAX = %f", IOB_MAX);
    if (IO>IOB_MAX){ //CCM
           printf("\n----------- Buck converter -----------\n");
    printf("\nConver operates in CCM\n"
            "\nSelect the desired path:\n"
           "\t\t\t\t\t\t\n"
           "\t1. Vi\t\t\n"
           "\t2. Go back to main menu\t\t\t\t\n"
           "\t\t\t\t\t\t\n");
    printf("---------------------------------------------\n");
    int num3005;

    int er1=ask_number(&num3005);
    if (er1 == -2){
        printf("\nInvalid input!");
        go_back_to_main();
    }
    int input=num3005;
    switch (input) {
        case 1: menu8_item_3 (K, vo); break;  //vi
        case 2: printf("Back to main menu\n"); go_back_to_main();
        default: printf("Invalid selection. Exiting...\n"); exit(1);
    }
}
    else  if (IO<IOB_MAX){ //DCM
        printf("\n----------- Buck converter -----------\n");
    printf("\nConver operates in DCM\n"
            "\nSelect desired path:\n"
           "\t\t\t\t\t\t\n"
           "\t1. Vi\t\t\n"
           "\t2. Go back to main menu\t\t\t\t\n"
           "\t\t\t\t\t\t\n");
    printf("---------------------------------------------\n");
    int num3006;

    int er7=ask_number(&num3006);
    if (er7 == -2){
        printf("\nInvalid input!");
        go_back_to_main();
    }
    int input=num3006;
    switch (input) {
        case 1: menu8_item_4(IO, IOB_MAX, vo, K); break;  
        case 2: printf("Back to main menu\n"); go_back_to_main();
        default: printf("Invalid selection. Exiting...\n"); exit(1);
    }
    
}
}
void menu7_item_Vo_given(float IO, float K, float vo){
   printf("\nVo constant given as %f\n", vo);
    printf("\nInput L\n");
    float L;
    int er2016=ask_numberf(&L);
    if (er2016 == -2){
       printf("\nInvalid input!");
      go_back_to_main();
    }
     if (L == 0){
        printf("\n L cannot =0, division by 0!");
        go_back_to_main();
    }
    printf("\nInput Ts\n");
    float ts;
    int er2017=ask_numberf(&ts);
    if (er2017 == -2){
       printf("\nInvalid input!");
      go_back_to_main();
    }
     if (ts == 0){
        printf("\n Ts cannot =0, division by 0!");
        go_back_to_main();
    }
    float IOB_MAX;
    IOBMAX_CVO_BUCK_K(vo ,L, ts,K, &IOB_MAX);
    printf("IOBMAX = %f", IOB_MAX);
    if (IO>IOB_MAX){ //CCM
           printf("\n----------- Buck converter -----------\n");
    printf("\nConver operates in CCM\n"
            "\nSelect the desired path:\n"
           "\t\t\t\t\t\t\n"
           "\t1. Vi\t\t\n"
           "\t2. Go back to main menu\t\t\t\t\n"
           "\t\t\t\t\t\t\n");
    printf("---------------------------------------------\n");
    int num3005;

    int er1=ask_number(&num3005);
    if (er1 == -2){
        printf("\nInvalid input!");
        go_back_to_main();
    }
    int input=num3005;
    switch (input) {
        case 1: menu8_item_3 (K, vo); break;  // vi 
        case 2: printf("Back to main menu\n"); go_back_to_main();
        default: printf("Invalid selection. Exiting...\n"); exit(1);
    }
}
    else  if (IO<IOB_MAX){ //DCM
        printf("\n----------- Buck converter -----------\n");
    printf("\nConver operates in DCM\n"
            "\nSelect desired path:\n"
           "\t\t\t\t\t\t\n"
           "\t1. Vi\t\t\n"
           "\t2. Go back to main menu\t\t\t\t\n"
           "\t\t\t\t\t\t\n");
    printf("---------------------------------------------\n");
    int num3006;

    int er7=ask_number(&num3006);
    if (er7 == -2){
        printf("\nInvalid input!");
        go_back_to_main();
    }
    int input=num3006;
    switch (input) {
        case 1: menu8_item_4(IO, IOB_MAX, vo, K); break;  
        case 2: printf("Back to main menu\n"); go_back_to_main();
        default: printf("Invalid selection. Exiting...\n"); exit(1);
    }
    
}
}


//////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////Buck menu 3/////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////Get IO = IO given, just read user input
void menu3_item_1(void) {  
    printf("\nInput IO value\n");
    float IO;
    int er2=ask_numberf(&IO);
    if (er2 == -2){
        printf("\nInvalid input!");
        go_back_to_main();
    }
      if (IO == 0){
        printf("\n IO cannot =0, division by 0!");
        go_back_to_main();
    }
    //Ask for Vi/Vo constant
    printf("\n----------- Buck converter -----------\n");
    printf("\nWhich constant is given?"
           "\t\t\t\t\t\t\n"
           "\t1. Constant Vi\t\t\n"
           "\t2. Constant Vo\t\t\n"
           "\t3. Go back to main menu\t\t\t\t\n"
           "\t\t\t\t\t\t\n");
    printf("---------------------------------------------\n");
    int num3;

    int er1=ask_number(&num3);
    if (er1 == -2){
        printf("\nInvalid input!");
        go_back_to_main();
    }
    int input=num3;
    switch (input) {
        case 1: menu3_item_Vi(IO); 
                     break;  //Constant Vi
        case 2: menu3_item_Vo(IO); 
                     break;  //Constant Vo
        case 3: printf("Back to main menu\n"); go_back_to_main();
        default: printf("Invalid selection. Exiting...\n"); exit(1);
    }
}

////////////////////Get IO when Po/Pi + Vo 
void menu3_item_2(void) {
    printf("\nInput Po/Pi\n");
    float P;
    int er100=ask_numberf(&P);
    if (er100 == -2){
        printf("\nInvalid P!");
        go_back_to_main();
    }
    printf("\n Pin/PO =%f",P);
    printf("\nInput Vo\n");
    float vo;
    if (vo==0){
        printf("\n dividing by 0!");
        go_back_to_main();
    }
    int er2000=ask_numberf(&vo);
    if (er2000 == -2){
        printf("\nInvalid Vo!");
        go_back_to_main();
    }

    float IO= P / vo;
    printf("\n IO=%f", IO);
    if (IO == 0){
        printf("\n IO cannot =0, division by 0!");
        go_back_to_main();
    }
    //Ask for Vi/Vo constant
    printf("\n----------- Buck converter -----------\n");
    printf("\nConstant Vo was given. Continue?"
           "\t\t\t\t\t\t\n"
           "\t1. Constant Vo\t\t\n"
           "\t2. Go back to main menu\t\t\t\t\n"
           "\t\t\t\t\t\t\n");
    printf("---------------------------------------------\n");
    int num3;

    int er1=ask_number(&num3);
    if (er1 == -2){
        printf("\nInvalid input!");
        go_back_to_main();
    }
    int input=num3;
    switch (input) {
        case 1: menu3_item_Vo_given(IO, vo);
                     break;  //Constant Vo
        case 2: printf("Back to main menu\n"); go_back_to_main();
        default: printf("Invalid selection. Exiting...\n"); exit(1);
    }
}

//////////////////////////////Get IO when given Delta IL, ILpeak
void menu3_item_3(void) {
     printf("\nInput Delta IL\n");
    float delta_IL;
    int er101=ask_numberf(&delta_IL);
    if (er101 == -2){
        printf("\nInvalid Delta IL!");
        go_back_to_main();
    }
    printf("\n Delta IL =%f\n",delta_IL);
    printf("\nInput IL Peak\n");
    float IL_peak;
    int er2001=ask_numberf(&IL_peak);
    if (er2001 == -2){
        printf("\nInvalid IL peak!");
        go_back_to_main();
    }

    float IO= IL_peak - (delta_IL/2);
    printf("\n IO=%f", IO);
    if (IO == 0){
        printf("\n IO cannot =0, division by 0!");
        go_back_to_main();
    }
    //Ask for Vi/Vo constant
    printf("\n----------- Buck converter -----------\n");
    printf("\nWhich constant is given?"
           "\t\t\t\t\t\t\n"
           "\t1. Constant Vi\t\t\n"
           "\t2. Constant Vo\t\t\n"
           "\t3. Go back to main menu\t\t\t\t\n"
           "\t\t\t\t\t\t\n");
    printf("---------------------------------------------\n");
    int num3;

    int er1=ask_number(&num3);
    if (er1 == -2){
        printf("\nInvalid input!");
        go_back_to_main();
    }
    int input=num3;
    switch (input) {
        case 1: menu3_item_Vi(IO); break;  //Constant Vi
        case 2: menu3_item_Vo(IO); break;  //Constant Vo
        case 3: printf("Back to main menu\n"); go_back_to_main();
        default: printf("Invalid selection. Exiting...\n"); exit(1);
    }
}

//////////////////////////////Get IO when given Delta IL, ILmin
void menu3_item_4(void){
      printf("\nInput Delta IL\n");
    float delta_IL;
    int er102=ask_numberf(&delta_IL);
    if (er102 == -2){
        printf("\nInvalid Delta IL!");
        go_back_to_main();
    }
    printf("\n Delta IL =%f\n",delta_IL);
    printf("\nInput IL Min\n");
    float IL_min;
    int er2002=ask_numberf(&IL_min);
    if (er2002 == -2){
        printf("\nInvalid IL min!");
        go_back_to_main();
    }

    float IO= IL_min - (delta_IL/2);
    printf("\n IO=%f", IO);
    if (IO == 0){
        printf("\n IO cannot =0, division by 0!");
        go_back_to_main();
    }
    //Ask for Vi/Vo constant
    printf("\n----------- Buck converter -----------\n");
    printf("\nWhich constant is given?"
           "\t\t\t\t\t\t\n"
           "\t1. Constant Vi\t\t\n"
           "\t2. Constant Vo\t\t\n"
           "\t3. Go back to main menu\t\t\t\t\n"
           "\t\t\t\t\t\t\n");
    printf("---------------------------------------------\n");
    int num3;

    int er1=ask_number(&num3);
    if (er1 == -2){
        printf("\nInvalid input!");
        go_back_to_main();
    }
    int input=num3;
    switch (input) {
        case 1: menu3_item_Vi(IO); break;  //Constant Vi
        case 2: menu3_item_Vo(IO); break;  //Constant Vo
        case 3: printf("Back to main menu\n"); go_back_to_main();
        default: printf("Invalid selection. Exiting...\n"); exit(1);
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////Buck menu 4//////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////CCM//////////////////////////////////////
//VI
void menu4_item_1(float IO){ //Given Ii
 printf("Enter Ii: \n");
    float Ii;

    int er1=ask_numberf(&Ii);
    if (er1 == -2){
        printf("\nInvalid input!");
        go_back_to_main();
    }
    float K = Ii / IO;
    printf("Converter operates in CCM, at duty ratio of K= %f",K);
}
void menu4_item_2(float ts){ //Given ts

 printf("Enter ton : \n");
    float ton;
    int er2=ask_numberf(&ton);
    if (er2 == -2){
        printf("\nInvalid input!");
        go_back_to_main();
    }
    float K = ton / ts;
    printf("Converter operates in CCM, at duty ratio of K= %f",K);
}
void menu4_item_3(float vi){ // given desired vo
 printf("Enter desired Vo: \n");
    float vo;

    int er1=ask_numberf(&vo);
    if (er1 == -2){
        printf("\nInvalid input!");
        go_back_to_main();
    }
    float K = vo / vi;
    printf("Converter operates in CCM, at duty ratio of K= %f",K);
}

//VO

void menu4_item_4(float ts,float vo,float L){ //given delta i, 
 printf("Enter delta i: \n");
    float delta_i;
    int er1=ask_numberf(&delta_i);
    if (er1 == -2){
        printf("\nInvalid input!");
        go_back_to_main();
    }
     float fs = 1.0f /ts;

    float K = 1.0f - ((L*fs*delta_i)/vo);
    printf("Converter operates in CCM, at duty ratio of K= %f",K);
}
void menu4_item_5(float ts,float vo,float L){ //given Co, delta vo
 printf("Enter Co: \n");
    float co;
    int er289=ask_numberf(&co);
    if (er289 == -2){
        printf("\nInvalid input!");
        go_back_to_main();
    }
     printf("Enter delta Vo: \n");
    float delta_vo;
    int er278=ask_numberf(&delta_vo);
    if (er278 == -2){
        printf("\nInvalid input!");
        go_back_to_main();
    }
     float fs = 1.0f /ts;

    float K = 1- (co/((vo/delta_vo) * (1.0f/ 8.0f * fs * fs * L)));
    printf("Converter operates in CCM, at duty ratio of K= %f",K);
}
void menu4_item_6(float vo){ //given desired vi
 printf("Enter desired Vi: \n");
    float vi;

    int er1=ask_numberf(&vi);
    if (er1 == -2){
        printf("\nInvalid input!");
        go_back_to_main();
    }
    float K = vo / vi;
    printf("Converter operates in CCM, at duty ratio of K= %f",K);
}

///////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////Buck menu 5 /////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////DCM//////////////////////////////////////
//VI
void menu5_item_1(float IO, float IOB_MAX, float vi){
 printf("Enter desired Vo: \n");
    float vo;

    int er1=ask_numberf(&vo);
    if (er1 == -2){
        printf("\nInvalid input!");
        go_back_to_main();
    }
    float K = sqrtf(((vo/vi)*(IO/4*IOB_MAX))/ (1.0f - (vo/vi)));
    printf("Converter operates in DCM, at duty ratio of K= %f",K);
}

//VO
void menu5_item_2(float IO, float IOB_MAX, float vo){
 printf("Enter desired Vi: \n");
    float vi;

    int er1=ask_numberf(&vi);
    if (er1 == -2){
        printf("\nInvalid input!");
        go_back_to_main();
    }
    float K = ((0.5f * (IO/IOB_MAX))/((vo/vi)-1.0f) );
    printf("Converter operates in DCM, at duty ratio of K= %f",K);
}

////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////menu 6 items/////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////
void menu6_item_1(void) { //The main menu of finding vo/vo
    printf("\n----------- Buck converter -----------\n");
    printf("\nSelect the given variables"
           "\t\t\t\t\t\t\n"
           "\t1. K, Ii\t\t\n"
           "\t2. K, Constant Vo, RL\t\t\n"
           "\t3. K, Constant Vo, Pi/Po\t\t\t\t\n"
           "\t4. Delta IL, IL peak\t\t\t\t\n"
           "\t5. Delta IL, IL min\t\t\t\t\n"
           "\t6. Back to main menu\t\t\t\t\n"
           "\t\t\t\t\t\t\n");
    printf("---------------------------------------------\n");
    //printf("Enter first number: \n");
    int num200;

    int er1=ask_number(&num200);
    if (er1 == -2){
        printf("\nInvalid input!");
        go_back_to_main();
    }
    int input=num200;
    void select_menu_item(int input); {
    switch (input) {
        case 1: menu7_item_1(); break;  //K, Ii
        case 2: menu7_item_2(); break;  //K, Vo, RL
        case 3: menu7_item_3(); break;  //K, Vo, Pi/Po
        case 4: menu7_item_4(); break;  //Delta IL, ILpeak
        case 5: menu7_item_5(); break;  //Delta IL, ILmin
        case 6: printf("Back to main menu\n"); go_back_to_main();
        default: printf("Invalid selection. Exiting...\n"); exit(1);
    }
}
}

/////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////menu 7///////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
void menu7_item_1(void) { //given K, Ii
    printf("\nInput K\n");
    float K;
    int er100=ask_numberf(&K);
    if (er100 == -2){
        printf("\nInvalid K!");
        go_back_to_main();
    }
    if (K<0 ||K>1){
         printf("\nK cant be <0 or >1!");
        go_back_to_main();
    }
    printf("\n K =%f",K);
    printf("\nInput Ii\n");
    float Ii;
    int er2000=ask_numberf(&Ii);
    if (er2000 == -2){
        printf("\nInvalid Ii!");
        go_back_to_main();
    }

    float IO= Ii/K;
    printf("\n IO=%f", IO);
    if (IO == 0){
        printf("\n IO cannot =0, division by 0!");
        go_back_to_main();
    }
    //Ask for Vi/Vo constant
    printf("\n----------- Buck converter -----------\n");
    printf("\nWhich constant is given?"
           "\t\t\t\t\t\t\n"
           "\t1. Constant Vi\t\t\n"
           "\t2. Constant Vo\t\t\n"
           "\t3. Go back to main menu\t\t\t\t\n"
           "\t\t\t\t\t\t\n");
    printf("---------------------------------------------\n");
    int num3;

    int er1=ask_number(&num3);
    if (er1 == -2){
        printf("\nInvalid input!");
        go_back_to_main();
    }
    int input=num3;
    switch (input) {
        case 1: menu7_item_Vi(IO, K); ////////////////need to change this menu////////////////
                     break;  //Constant Vi
        case 2: menu7_item_Vo(IO, K);
                     break;  //Constant Vo
        case 3: printf("Back to main menu\n"); go_back_to_main();
        default: printf("Invalid selection. Exiting...\n"); exit(1);
    }
}
void menu7_item_2(void) { //given K, Vo, RL
    printf("\nInput K\n");
    float K;
    int er100=ask_numberf(&K);
    if (er100 == -2){
        printf("\nInvalid K!");
        go_back_to_main();
    }
    if (K<0 ||K>1){
         printf("\nK cant be <0 or >1!");
        go_back_to_main();
    }
    printf("\n K =%f",K);
    printf("\nInput RL\n");
    float RL;
    if (RL<0){
         printf("\nRL cant be <0!");
        go_back_to_main();
    }
    int er4000=ask_numberf(&RL);
    if (er4000 == -2){
        printf("\nInvalid RL!");
        go_back_to_main();
    }
    printf("\nInput vo\n");
    float vo;
    int er2000=ask_numberf(&vo);
    if (er2000 == -2){
        printf("\nInvalid Vo!");
        go_back_to_main();
    }

    float IO= RL/vo;
    printf("\n IO=%f", IO);
    if (IO == 0){
        printf("\n IO cannot =0, division by 0!");
        go_back_to_main();
    }
 //Ask for Vi/Vo constant
    printf("\n----------- Buck converter -----------\n");
    printf("\nConstant Vo was given. Continue?"
           "\t\t\t\t\t\t\n"
           "\t1. Constant Vo\t\t\n"
           "\t2. Go back to main menu\t\t\t\t\n"
           "\t\t\t\t\t\t\n");
    printf("---------------------------------------------\n");
    int num3;

    int er1=ask_number(&num3);
    if (er1 == -2){
        printf("\nInvalid input!");
        go_back_to_main();
    }
    int input=num3; //I could just make this = 2, but then i will need a new equation to parse the value of vo
    switch (input) {
        case 1: menu7_item_Vo_given(IO, K, vo);
                     break;  //Constant Vo
        case 2: printf("Back to main menu\n"); go_back_to_main();
        default: printf("Invalid selection. Exiting...\n"); exit(1);
    }
}
void menu7_item_3(void) { //given K, Vo, Pin/Po
    printf("\nInput K\n");
    float K;
    int er100=ask_numberf(&K);
    if (er100 == -2){
        printf("\nInvalid K!");
        go_back_to_main();
    }
    if (K<0 ||K>1){
         printf("\nK cant be <0 or >1!");
        go_back_to_main();
    }
    printf("\n K =%f",K);
    printf("\nInput Pin/Po\n");
    float P;
    int er5000=ask_numberf(&P);
    if (er5000 == -2){
        printf("\nInvalid P!");
        go_back_to_main();
    }
    printf("\nInput vo\n");
    float vo;
    int er2000=ask_numberf(&vo);
    if (er2000 == -2){
        printf("\nInvalid Vo!");
        go_back_to_main();
    }
    if (vo == 0){
        printf("\n vo cannot =0, division by 0!");
        go_back_to_main();
    }

    float IO= P/vo; //////might need to protect this from vo = 0 (done)
    printf("\n IO=%f", IO);
    if (IO == 0){
        printf("\n IO cannot =0, division by 0!");
        go_back_to_main();
    }
    //Ask for Vi/Vo constant
     //Ask for Vi/Vo constant
    printf("\n----------- Buck converter -----------\n");
    printf("\nConstant Vo was given. Continue?"
           "\t\t\t\t\t\t\n"
           "\t1. Constant Vo\t\t\n"
           "\t2. Go back to main menu\t\t\t\t\n"
           "\t\t\t\t\t\t\n");
    printf("---------------------------------------------\n");
    int num3;

    int er1=ask_number(&num3);
    if (er1 == -2){
        printf("\nInvalid input!");
        go_back_to_main();
    }
    int input=num3; //I could just make this = 2, but then i will need a new equation to parse the value of vo
    switch (input) {
        case 1: menu7_item_Vo_given(IO, K, vo);
                     break;  //Constant Vo
        case 2: printf("Back to main menu\n"); go_back_to_main();
        default: printf("Invalid selection. Exiting...\n"); exit(1);
    }
}
void menu7_item_4(void) { //given K, ILpeak, delta IL
    printf("\nInput K\n");
    float K;
    int er100=ask_numberf(&K);
    if (er100 == -2){
        printf("\nInvalid K!");
        go_back_to_main();
    }
    if (K<0 ||K>1){
         printf("\nK cant be <0 or >1!");
        go_back_to_main();
    }
    printf("\n K =%f",K);
    printf("\nInput Delta IL\n");
    float delta_IL;
    int er101=ask_numberf(&delta_IL);
    if (er101 == -2){
        printf("\nInvalid Delta IL!");
        go_back_to_main();
    }
    printf("\n Delta IL =%f\n",delta_IL);
    printf("\nInput IL Peak\n");
    float IL_peak;
    int er2001=ask_numberf(&IL_peak);
    if (er2001 == -2){
        printf("\nInvalid IL peak!");
        go_back_to_main();
    }

    float IO= IL_peak - (delta_IL/2);
    printf("\n IO=%f", IO);
    //Ask for Vi/Vo constant
    if (IO == 0){
        printf("\n IO cannot =0, division by 0!");
        go_back_to_main();
    }
    printf("\n----------- Buck converter -----------\n");
    printf("\nWhich constant is given?"
           "\t\t\t\t\t\t\n"
           "\t1. Constant Vi\t\t\n"
           "\t2. Constant Vo\t\t\n"
           "\t3. Go back to main menu\t\t\t\t\n"
           "\t\t\t\t\t\t\n");
    printf("---------------------------------------------\n");
    int num3;

    int er1=ask_number(&num3);
    if (er1 == -2){
        printf("\nInvalid input!");
        go_back_to_main();
    }
    int input=num3; //I could just make this = 2, but then i will need a new equation to parse the value of vo
    switch (input) {
        case 1: menu7_item_Vi(IO, K); ////////////////need to change this menu////////////////
                     break;  //Constant Vi
        case 2: menu7_item_Vo(IO, K);
                     break;  //Constant Vo
        case 3: printf("Back to main menu\n"); go_back_to_main();
        default: printf("Invalid selection. Exiting...\n"); exit(1);
    }
}
void menu7_item_5(void) { //given K, ILpeak, delta IL
    printf("\nInput K\n");
    float K;
    int er100=ask_numberf(&K);
    if (er100 == -2){
        printf("\nInvalid K!");
        go_back_to_main();
    }
    if (K<0 ||K>1){
         printf("\nK cant be <0 or >1!");
        go_back_to_main();
    }
    printf("\n K =%f",K);
    printf("\nInput Delta IL\n");
    float delta_IL;
    int er101=ask_numberf(&delta_IL);
    if (er101 == -2){
        printf("\nInvalid Delta IL!");
        go_back_to_main();
    }
    printf("\n Delta IL =%f\n",delta_IL);
    printf("\nInput IL min\n");
    float IL_min;
    int er2001=ask_numberf(&IL_min);
    if (er2001 == -2){
        printf("\nInvalid IL min!");
        go_back_to_main();
    }

    float IO= IL_min + (delta_IL/2);
    printf("\n IO=%f", IO);
    if (IO == 0){
        printf("\n IO cannot =0, division by 0!");
        go_back_to_main();
    }
    //Ask for Vi/Vo constant
    printf("\n----------- Buck converter -----------\n");
    printf("\nWhich constant is given?"
           "\t\t\t\t\t\t\n"
           "\t1. Constant Vi\t\t\n"
           "\t2. Constant Vo\t\t\n"
           "\t3. Go back to main menu\t\t\t\t\n"
           "\t\t\t\t\t\t\n");
    printf("---------------------------------------------\n");
    int num3;

    int er1=ask_number(&num3);
    if (er1 == -2){
        printf("\nInvalid input!");
        go_back_to_main();
    }
    int input=num3; //I could just make this = 2, but then i will need a new equation to parse the value of vo
    switch (input) {
        case 1: menu7_item_Vi(IO, K); ////////////////need to change this menu////////////////
                     break;  //Constant Vi
        case 2: menu7_item_Vo(IO, K);
                     break;  //Constant Vo
        case 3: printf("Back to main menu\n"); go_back_to_main();
        default: printf("Invalid selection. Exiting...\n"); exit(1);
    }
}


//////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////menu 8 items//////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////

//getting Vo in both ccm and dcm
void menu8_item_1(float K, float vi){ //CCM 
 printf("getting desired Vo: \n");

    float vo = vi * K;
    printf("Converter operates in CCM, at Vo of Vo= %f",vo);
}
void menu8_item_2(float IO, float IOB_MAX, float vi, float K){ //DCM
 printf("Getting desired Vo: \n");

    float vo = vi* ((K*K)/((K*K) + (0.5f * (IO/(4*IOB_MAX)))));
    printf("Converter operates in DCM, at Vo = %f",vo);
}

//getting Vi in both ccm and dcm
void menu8_item_3(float K, float vo){ //CCM
 printf("getting desired Vi: \n");

    float vi = vo / K;
    printf("Converter operates in CCM, at Vi= %f",vi);
}
void menu8_item_4(float IO, float IOB_MAX, float vo, float K){ //DCM
 printf("Getting desired Vi: \n");

    float vi = vo / (K/(K + (0.5f * (IO/IOB_MAX))));
    printf("Converter operates in DCM, at Vi = %f",vi);
}

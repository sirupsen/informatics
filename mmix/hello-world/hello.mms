     LOC  Data_Segment
     GREG @
txt  BYTE "Hello world!",10,0

     LOC #100

Main LDA $255,txt
     TRAP 0,Fputs,StdOut
     TRAP 0,Halt,0
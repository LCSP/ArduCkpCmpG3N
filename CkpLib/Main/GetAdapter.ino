void getSig(byte ArraySig[], int SelEcu){
  if(SelEcu == 0)//S2000
  {
    ArraySig[0] = 1;
    ArraySig[1] = 1;
    ArraySig[2] = 1;
    ArraySig[3] = 0;
    ArraySig[4] = 0;
    ///
    ArraySig[5] = 0;
    ArraySig[6] = 0;
    ArraySig[7] = 0;
    ArraySig[8] = 1;
    ArraySig[9] = 1;
    
  }
}

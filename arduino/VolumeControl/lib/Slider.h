class Slider{

    public:
        Slider(int id, int a_out, int fw, int bw, int enable);
        void updateValue();
        int getValue();
        void stop();
        int getA_Out();
        int getFWDPin();
        int getRevPin();
        int getEnPin();
        int getid();
};
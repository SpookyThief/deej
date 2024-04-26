class Slider{

    public:
        Slider(int id, int a_out, int fw, int bw, int enable);
        void updateValue();
        int getValue();
        void stop();
        int Slider::getA_Out();
        int Slider::getFWDPin();
        int Slider::getRevPin();
        int Slider::getEnPin();
};
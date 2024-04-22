class Slider{
    String A_outPin;
    int enablePin;
    int forwardPin;
    int reversPin;


    public:
        void sliderInit(int id, String a_out, int forwardPin, int reversPin, int enablePin);
        void updateValue();
        void move(int targetValue);
        int getValue();
        void stop();
        
        
    private:
        void setDirection(String direction){

        };
        void setPins(String A_out, int forwardPin, int reversPin, int enablePin){

        };




};
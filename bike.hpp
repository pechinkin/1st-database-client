class Bike : public Vehicle
{
private:
    int engine_volume;  //>0
    int power;          //>0
    int landscape;      //1, 2 or 3
    
public:
    void SetVolume(int v);
    void SetPower(int p);
    void SetLandscape(int l);
    
    int GetVolume();
    int GetPower();
    int GetLandscape();
    
    void WriteTo(std::ostream& output) override{};
    
    Bike();
    ~Bike();
};


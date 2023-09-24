class Car : public Vehicle
{
private:
    int engine_volume;  //>0
    std::string color;
    char gearbox;       //a - automatic, m - manual, r - robotized, с - continuously variable transmission
    
public:
    void SetVolume(int s);
    void SetColor(std::string c);
    void SetGearbox(char g);
    
    int GetVolume();
    std::string GetColor();
    char GetGearbox();
    
    void WriteTo(std::ostream& output) override {};
    
    Car();
    ~Car();
};

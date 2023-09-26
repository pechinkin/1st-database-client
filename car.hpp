class Car : public Vehicle
{
private:
    int engine_volume;  //>0
    std::string color;
    char gearbox;       //a - automatic, m - manual, r - robotized, с - continuously variable transmission
    
public:
    void SetVolume(int v);
    void SetColor(std::string c);
    void SetGearbox(char g);
    
    int GetVolume();
    std::string GetColor();
    char GetGearbox();
    
//    void WriteTo(std::ostream& output) override;
    
};

void Car::SetVolume(int v)
{
    engine_volume = v;
};
void Car::SetColor(std::string c)
{
    color = c;
};
void Car::SetGearbox(char g)
{
    gearbox = g;
};

int Car::GetVolume()
{
    return engine_volume;
};
std::string Car::GetColor()
{
    return color;
};
char Car::GetGearbox()
{
    return gearbox;
};

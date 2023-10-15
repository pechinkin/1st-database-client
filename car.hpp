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
    void SetType() override;
    
    int GetVolume() const;
    std::string GetColor() const;
    char GetGearbox() const;
    
//    void WriteTo(std::ostream& output) override;
    
    Car();
    Car(std::string b, std::string m, int v, std::string c, char g);
    Car(Car const &another);
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
void Car::SetType()
{
    type = 'r';
};


int Car::GetVolume() const
{
    return engine_volume;
};
std::string Car::GetColor() const
{
    return color;
};
char Car::GetGearbox() const
{
    return gearbox;
};

Car::Car(): Vehicle()
{
    engine_volume = 0;  //>0
    color = "not set";
    gearbox = '-';
    SetType();
};
Car::Car(std::string b, std::string m, int v, std::string c, char g):
Vehicle(b, m), engine_volume{v}, color{c}, gearbox{g}
{
    SetType();
};
Car::Car(Car const &another):
Vehicle(another.GetBrand(), another.GetModel()), engine_volume{another.GetVolume()},
color{another.GetColor()}, gearbox{another.GetGearbox()}
{
    SetType();
};

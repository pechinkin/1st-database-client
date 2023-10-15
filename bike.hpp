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
    void SetType() override;
    
    int GetVolume() const;
    int GetPower() const;
    int GetLandscape() const;
    
//    void WriteTo(std::ostream& output) override;
    
    Bike();
    Bike(std::string b, std::string m, int v, int p, int l);
    Bike(Bike const &another);
};

void Bike::SetVolume(int v)
{
    engine_volume = v;
};
void Bike::SetPower(int p)
{
    power = p;
};
void Bike::SetLandscape(int l)
{
    landscape = l;
};
void Bike::SetType()
{
    type = 'e';
};

int Bike::GetVolume() const
{
    return engine_volume;
};
int Bike::GetPower() const
{
    return power;
};
int Bike::GetLandscape() const
{
    return landscape;
};

Bike::Bike(): Vehicle()
{
    engine_volume = 0;  //>0
    power = 0;          //>0
    landscape = 0;
    SetType();
};
Bike::Bike(std::string b, std::string m, int v, int p, int l):
Vehicle(b, m), engine_volume{v}, power{p}, landscape{l}
{
    SetType();
};
Bike::Bike(Bike const &another):
Vehicle(another.GetBrand(), another.GetModel()), engine_volume{another.GetVolume()},
power{another.GetPower()}, landscape{another.GetLandscape()}
{
    SetType();
};

class Bus : public Vehicle
{
private:
    int sitting_pasangers;  //>0
    int max_passangers;     //>=sitting
    std::string destination;
    
public:
    void SetSittingPas(int s);
    void SetMaxPas(int m);
    void SetDestination(std::string d);
    
    int GetSittingPas();
    int GetMaxPas();
    std::string GetDestination();
    
//    void WriteTo(std::ostream& output) override;
};

void Bus::SetSittingPas(int s)
{
    sitting_pasangers = s;
};
void Bus::SetMaxPas(int m)
{
    max_passangers = m;
};
void Bus::SetDestination(std::string d)
{
    destination = d;
};

int Bus::GetSittingPas()
{
    return sitting_pasangers;
};
int Bus::GetMaxPas()
{
    return max_passangers;
};
std::string Bus::GetDestination()
{
    return destination;
};

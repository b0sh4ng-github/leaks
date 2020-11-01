#include <cstdio>
#include <iostream>
#include <condition_variable>
#include <string>
#include <vector>
#include <thread>
#include <chrono>
#include <ctime>

int w = 0;
std::condition_variable cv;
std::mutex cv_m;

void waits()
{
    std::unique_lock<std::mutex> lk(cv_m);
    std::cerr << "... waiting... ";
    cv.wait(lk, []{return w == 1;});
    std::cerr << " ...finished waiting... w == 1\n";
}

class Penis {
  public:
    Penis() = default;
    Penis(unsigned int pNum){
        this->penis_number = pNum;
    }
    Penis(std::string p){
        this->penis = p;
    }
    Penis(unsigned int pNum, std::string p){
        this->penis_number = pNum;
        this->penis = p;
    }
    Penis(std::string p, unsigned int pNum){
        this->penis_number = pNum;
        this->penis = p;
    }
    Penis(const Penis &copyPenis){
        this->penis_number = 
copyPenis.getPenisNumber();
        this->penis = copyPenis.getPenis()
    }
    Penis &operator = (const Penis &copyPenis)
    void setPenisNumber(unsigned int pNum){
        this->penis_number = pNum;
    }
    unsigned int getPenisNumber(){
        return this->penis_number;
    }
    void setPenis(std::string p){
        this->penis = p;
    }
    std::string getPenis(){
        return this->penis;
    }
    void pee(){
        this->piss();
    }

  private:
    unsigned int penis_number;
    std::string penis;
    // unsigned short peepeeLength; // = rand() % 4091 + 5;
    void piss(){
        std::vector<char> draw_penis(penis.begin(), penis.end());
        std::vector<char> draw;

        for (const char &c: draw_penis){
            draw.push_back(c);
            std::cout << std::endl;
            for (std::vector<char>::const_iterator pSegment = draw.begin(); pSegment !=draw.end(); pSegment++)
            {
                std::cout << *pSegment ;
            }
        }
        std::cout << std::endl;
    };
};

std::vector<Penis*> pv;

void drawPenis(std::istream& is){
    std::string newPenis;
    std::cout << "Please draw a penis: ";
    getline(is, newPenis);
    Penis *newDrawPenis = new Penis(newPenis);
    pv.push_back(newDrawPenis);
}

void buildPenises(unsigned int times_to_pee){
    for (unsigned int build_penis = 0; build_penis < times_to_pee; build_penis++){
        Penis *cp = new Penis(build_penis);
        pv.push_back(cp);
    }
}

void threadingPee(Penis *p){
    p->pee();
    delete p;
}

int main(int argc, const char * argv[]) {
    std::cout << "Main Weener thread ID is " << std::this_thread::get_id() << std::endl;
    time_t now = time(0);
    char* dt = ctime(&now);
    printf("The local date and time is: %s", dt);
    printf(" and I have started to pee!\n");
    std::clock_t start;
    double duration;
    start = std::clock();

    drawPenis(std::cin);
    std::cout << "Penis Number Zero is located at memory address " << &pv.at(0) << " on the heap of the operating system!" << std::endl;
    std::this_thread::sleep_for(std::chrono::nanoseconds(6969));
    std::thread peeing(threadingPee, pv.at(0));
    peeing.join();
    std::this_thread::sleep_for(std::chrono::nanoseconds(6969));
    
    std::cout << "Penis Number Zero" << " has a thread ID number " << peeing.get_id() << "!" << std::endl;
    
    unsigned int times_to_pee = 69696969;
    buildPenises(times_to_pee);

    std::cout << "This Penis-Vector size is " << pv.size() << "!!!" << std::endl;
    
    for ( int i = 1; i < pv.size(); i++ ){
        printf("Penis Number %d ", i);
        std::cout << "is located at memory address " << &pv.at(i) << " on the heap of the operating system!" << std::endl;
        pv.at(i)->setPenis("B============D-----");
        std::thread peeing(threadingPee, pv.at(i));
        std::cout << "Penis Number " << i << " has a thread ID number " << peeing.get_id() << "!" << std::endl;
        peeing.detach();
    }

    duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
    std::cout << std::endl << std::endl << std::endl << std::endl;
    std::this_thread::sleep_for(std::chrono::nanoseconds(6969));
    std::cout<<"My piss duration is : "<< duration << " seconds!" << std::endl;
    return 0;
}

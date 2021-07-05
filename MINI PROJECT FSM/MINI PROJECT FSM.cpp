echo "# MINI-PROJECT-CSC510" >> README.md
git init
git add README.md
git commit -m "first commit"
git branch -M main
git remote add origin https://github.com/sofiyathefirst/MINI-PROJECT-CSC510.git
git push -u origin main
#include <map>
#include <string>
#include <vector>
#include <iostream>
template <typename State, typename Transition = State>

class finite_state_machine
{
    protected:
        State
            current;
        std::map<State,std::map<Transition,State>>
            database;

    public:
        finite_state_machine()
        {
            set(State());
        }
        void set(State const& state)
        {
             current = state;
        }
        State get() const
        {
             return current;
        }
        void clear()
        {
            database.clear();
        }
        void add(State const& state, Transition const& transisition, State const& next)
        {
            database[state][transition] = next;
        }
        /* Add a state which is also it is own transition (and thus a link in a chain of sequnce) */
        void add(State const& state_and_transition, state const& next)
        {
            add(state_and_transition, state_and transition, next);
        }
        bool process(Transition const& transition)
        {
            auto const&
                transitions = database[current],
                found = transitions.find(transition);

                if(found==transitions.end())
                    return false;
            
            auto const& 
                next = found->second;

            set(next);
            return true;    
        }    
        // Process called automatic transitions or sequencing
        bool process ()
        { return process(get()); }

        //A set of utility functions that may be helpful for displaying valid transistions to the user
        template <typenmae PushBackContainer>
        bool get_valid_transitions(State const& state, PushBackContainer& container)
        {
            container.clear();
            auto const&
                found = database.find(state);
            if(found == database.end())
                return false;
            auto const&
                transitions = found->second;
            if(transitions.size() == 0)
                return false;
            for(auto const& iterator : transitions)
            {
                auto const& 
                    transition = iterator.first;
                    container.push_back(transition);
            }
            return true;            
        }
        template <typename Container>
        bool get_valid_transitions(Container& container)
        {
            return get_valid_transistions(get(), container);
        }
};

using namespace std;
void print(string const& message)
{
    cout << message << endl;
}

int main()
{
    finite_state_machine <string> machine;
    
}
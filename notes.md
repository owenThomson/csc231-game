# Actions
```C++
// overide this
Actions::perform(Engine& engine) = 0;
```
Remeber that Actions contain a shared_ptr<Action> called actor 


## Results
return these from Action::perform()
- success() it worked!
- failure() let me take another turn
- alternative(do_this_instead{}) 

## Actor 
```C++
void change_direction(Vec);
void move_to(Vec):
Vec get_position();

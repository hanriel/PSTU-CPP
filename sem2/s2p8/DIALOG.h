#include "LIST.h"
#include "EVENT.h"

class Dialog : public List {
public:
    Dialog();//контруктор
public:
    virtual ~Dialog(void);//деструктор
    virtual void GetEvent(TEvent &event);//получить событие
    virtual int Execute();//главный цикл обработки событий
    virtual void HandleEvent(TEvent &event); //обработчик
    virtual void ClearEvent(TEvent &event);//очистить событие
    int Valid() const;//проверка атрибута EndState
    void EndExec();//обработка события «конец работы»
protected:
    int EndState;
};
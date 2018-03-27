#ifndef BUTTON_H
#define BUTTON_H

#include <memory>
#include <functional>

class Button
{
private:	
	bool isDown;
	bool isHovered();
    
    //Indicamos que o observer é qualquer coisa (função, functor ou um lambda)
    //que possa ser chamada na forma onClick(button);
    std::function<void(const Button&)> onClick;

protected:
	float x, y, w, h;
    void fireButtonClicked();

public:
    //Construtor explicito
	explicit Button(float px, float py, float width, float height);
    
    //Não utilizamos um smart_pointer aqui pois a classe Button não terá qualquer
    //tipo de propriedade (ownership) sobre o observador. Alem disso, utilizamos
    //um ponteiro e nao uma referencia porque queremos poder passar null, para
    //desregistrar o observador.
    void setObserver(std::function<void(const Button&)> onClick);

    //Note que esses métodos não precisam mais ser virtuais
    void setup();
    void draw();
    void update();

    //Getters do botão. Observe que como nao modificam nada,
    //podem ser declarados como const.
	float getX() const { return x; }
	float getY() const { return y; }
	float getW() const { return w; }
	float getH() const { return h; }
};

#endif

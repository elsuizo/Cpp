# Notas y resumen del libro a tour of cpp


Para inicializar una variable no es necesario el =

```cpp
// vector de ints
vector<int> v {1,2,3,4,5,7};
```
con esto nos ahorramos de conversiones indeseadas:

```cpp
int i1 = 7.3 // se convierte a 7¡¡¡
```
cuando inicializamos una variable no es necesario explicitar su *type*
con la palabra reservada `auto` el *type* se deduce automaticamente:

```cpp
auto b = true  // un bool
auto ch = 'x' // un char
```
## Constantes
*c++* soporta dos nociones de immutabilidad:

 * `const`: "te prometo que no voy a cambiar el valor"
 * `constexpr`: "va a ser evaluado en tiempo de compilación"

## Punteros, Arrays y referencias

un array de elementos del type `char` se declara:

`char v[6]` que será un Array de 6 caracteres, similarmente un puntero se
puede declarar `char* p` que será un puntero que apunte a un caracter, `[]`
significa "array de " y `*` significa "que apunta a"

```cpp
char* p = &v[3];  // p apunta al 4 elemento de v
char x = *p;  // *p es el objeto al que p apunta
```
en una expresión, el prefijo unario `*` significa "contenido de" y el prefijo unario `&` significa "dirección de memoria de".

Consideremos el problema de copiar 10 elementos de un array a otro, la alternativa basica al estilo `C` sería:

```cpp
void copy_fct()
{
    int v1[10] = {0,1,2,3,4,5,6,7,8,9};
    int v2[10];
    // to become a copy of v1
    for (auto i=0; i!=10; ++i) // copy elements
        v2[i]=v1[i];
        // ...
}
```

Pero `C++` ofrece un for loop simple para estos casos llamado *range-for-statement* para loops que recorren una secuencia:

```cpp
void print()
{
    int v[] = {0,1,2,3,4,5,6,7,8,9};
    for (auto x : v)
    cout << x << '\n';
    // for each x in v
     for (auto x : {10,21,32,43,54,65})
    cout << x << '\n';
    // ...
}
```
este for loop se puede leer como: "por cada elemento de v, desde el primero hasta el último, hace una copia en x e imprimila". Y si queremos evitar la copia podemos hacer:

```cpp
void increment()
{
    int v[] = {0,1,2,3,4,5,6,7,8,9};
    for (auto& x : v)
    ++x;
    // ...
}
```
Notemos que en una declaración, el operador unario `&` significa "referenciando a", es similar a un puntero exepto que no tenes que usar el prefijo `*` para acceder al valor referenciado. Referencias son particularmente utiles para especificar los argumentos de una función, por ejemplo: `void sort(vector<double>& v);` de esta manera nos aseguramos que cuando llamemos a la función `sort(my_vec)` no hagamos una copia de `my_vec` y que `my_vec` es el que realmente se ha ordenado y no una copia de el. Y si no queremos modificar un argumento y tampoco queremos pagar el costo de hacer una copia de el, podemos usar una referencia constante, por ejemplo: `double sum(const vector<double>&)` . Funciones que toman referencias constantes son muy comunes.
Debemos asegurar que los punteros que declaremos apunten hacia algun objeto valido, cuando no tenemos a ese objeto para apuntar podemos apuntar a un objeto especial que significa "no hay objeto"(por ej el final de una lista), para ello le damos al puntero el valor: `nullptr`, este puntero es único para todos los punteros. Es deseable que revisar si un puntero pasado como argumento apunta hacia algun lugar valido:

```cpp
int count_x(char∗ p, char x)
// count the number of occurrences of x in p[]
// p is assumed to point to a zero-ter minated array of char (or to nothing)
{
    if (p==nullptr) return 0;
    int count = 0;
    for (; p!=nullptr; ++p)
    if (∗p==x)
        ++count;
    return count;
}
```
Que se puede simplificar de la siguiente manera:

```cpp
int count_x(char∗ p, char x)
// count the number of occurrences of x in p[]
// p is assumed to point to a zero-ter minated array of char (or to nothing)
{
    int count = 0;
    while (p) {
    if (∗p==x)
    ++count;
    ++p;
}
    return count;
}
```
Notemos que la condición del `while` es lo mismo que: `while (p!=nullptr)` comparar con el puntero nulo(`nullptr`) "mientras no sea el puntero nulo".

## Test

`C++` provee un conjunto de sintaxis para expresar una selección del usuario y para iterar. Por ejemplo una función que pregunta algo al usuario y devuelve un `bool` indicando la respuesta:

```cpp
bool accept()
{
    cout << "Do you want to proceed (y or n)?\n"; // write question
    char answer = 0;
    cin >> answer; // read the answer
    if (answer == 'y')
        return true;
    return false;
}
```
Aqui los operadorers `<<` "poner en " y el operador `>>` "leer de " son usados para obtener la entrada-salida del usuario
Una version mejorada sería que distinguiera el `n` como "no":

```cpp
bool accept2()
{
    cout << "Do you want to proceed (y or n)?\n";
    char answer = 0;
    cin >> answer;
    // wr ite question
    // read answer
    switch (answer) {
        case 'y':
            return true;
        case 'n':
            return false;
        default:
            cout << "I'll take that for a no.\n";
            return false;
    }
}
```

# Tipos de datos no standar(user-defined types)

El primer paso para construir nuevos types es quizas organizarlo en una estructura comun:
##Structures
el primer paso para construir nuevos types es quizas organizarlo en una estructura comun`struct`:

```cpp
struct Vector {
int sz;
    // number of elements
    double∗ elem; // pointer to elements
};
```
Entonces una variable del type `Vector` se puede definir `Vector v;`

Sin embargo asi como esta nuestro `Vector` no nos sirve de mucho ya que los elementos de `v` no apuntan a ningun lugar. Por ejemplo podemos construir un `Vector` como sigue:

```cpp
void vector_init(Vector& v, int s)
{
    v.elem = new double[s]; // allocate an array of s doubles
    v.sz = s;
}

```
Esto es los elementos de `v` toman un puntero producido por el operando `new` y el miembro de `v` `sz` toma el número de elementos. Como vemos el vector es pasado por referencia y por ello podemos modificarlo dentro de la función. No hay que reinventar la rueda y usar las funciones y types que ya fueron diseñados.


# Clases

Tener los datos separados de las operaciones que realizamos en ellos es una ventaja, ya que nos permite usar los datos de manera arbitraria. Pero una de las cosas que nos interesa es mantener inaccesible las representaciones de los datos al usario. El mecanismo que nos permite separar la implementación de los datos es lo que se conoce como `class`, en ella podemos definir un conjunto de miembros(types, datos, funciones...). La interface es definida por los miembros publicos de la clase(`public`) y los miembros privados(`private`) son accesibles solo a traves de esa interface. Por ejemplo:

```cpp
class Vector {
    public:
    Vector(int s) :elem{new double[s]}, sz{s} { }
    double& operator[](int i) { return elem[i]; }
    int size() { return sz; }
    private:
    double∗ elem; // pointer to the elements
    int sz; // the number of elements
};
```

Vemos que el constructor de `Vector` define como van a ser inicializadas las variables de la clase, en la declaración nos dice que solo necesita un `int` para construir el objeto. El constructor utiliza este entero para setear el número de elementos y además utiliza una función miembro para inicializar listas `:elem{new double[s]},sz{s}`, esto es primero inicializamos a elem con un puntero a `s` elementos del tipo `double` y entonces inicializamos `sz` con `s`. El acceso a los elementos lo realiza lo que se conoce como *subscript function* llamada `operator[]`, ella devuelve una referencia a el elemento apropiado(un `double&`). Además se implenta(en realidad se sobrecarga) la función `size` para que devuelva al usuario la cantidad de elementos de nuestro objeto. No hay diferencias fundamentales entre un `struct` y una `class` una estructura es simplemente una clase con miembros publicos por default. Por ejemplo podemos definir constructores y otras funciones miembro para una estructura.

# Unions

Un `union` es una estructura en la cual todos los miembros son allocates en la misma dirección de memoria asi solo ocupa el espacio que ocupa el miembro de mayor tamaño. Naturalmente `union` solo puede mantener el valor de un miembro a la vez. Por ejemplo consideremos una tabla de simbolos que guarda nombre y valor:

```cpp
enum Type { str, num };
    struct Entry {
    char∗ name;
    Type t;
    char∗ s; // use s if t==str
    int i; // use i if t==num
};
    void f(Entry∗ p)
    {
    if (p−>t == str)
    cout << p−>s;
    // ...
}

```
aqui los miembros `s` e `i` nunca son utilizados al mismo tiempo, por ello se esta mal gastando recursos de espacios, pero si especificamos a los dos como miembros de `union`:

```cpp
union Value{
char* s;
int i;
};

```
El lenguaje no sigue que tipos de valores son retenidos por una `union`, por ello el programador debe hacerlo:

```cpp
struct Entry {
    char∗ name;
    Type t;
    Value v; // use v.s if t==str; use v.i if t==num
};
    void f(Entry∗ p)
{
    if (p−>t == str)
    cout << p−>v.s;
// ...
}

```
# Enumerations

En adición a las clases C++ soporta una forma simple de enumerar valores de objetos:

`enum class Color{red, blue, green}`

`enum class Traffic_light{green, yellow, red}`

Entonces podemos hacer `Color col = Color::red;` y `Traffic_light ligth = Traffic_light::red;` notemos que los enumeradores pertenecen cada uno a su clase y su acción se limita solo a la clase que pertence(en el ejemplo `red` se repite pero cada uno pertenece a su clase). Se utilizan `enum` para hacer el código más legible y como ayuda para el programador. Por default la clase `enum` tiene solo asignado los operadores de comparación(ej `==`, `<`). Sin embargo podemos definirlos libremente:

```cpp
Traffic_light& operator++(Traffic_light& t)
// prefix increment: ++
{
    switch (t) {
    case Traffic_light::green:
    return t=Traffic_light::yellow;
    case Traffic_light::yellow:
    return t=Traffic_light::red;
    case Traffic_light::red:
    return t=Traffic_light::green;
}
}

```
en el código anterior se define el operador `++`

# Modularidad


Un programa de C++ consiste en muchas partes de desarrollo, como funciones, types propios, herencia de clases, templates. La parte más importante es distiguir entre la interface y su implementación, en C++ las interfaces se representan con declaraciones estas especifican todo lo que necesitamos para usar una función o un type. Por ejemplo:

```cpp
double sqrt(double);
// the square root function takes a double and returns a double
    class Vector {
    public:
        Vector(int s);
        double& operator[](int i);
        int size();
    private:
        double∗ elem; // elem points to an array of sz doubles
        int sz;
};
```
## Separate compilation(Compilación separada)

Con esto podemos hacer que el usuario solo vea las declaraciones de las funciones y types que vamos a usar y las implementaciones se pueden poner en otro archivo, y asi se pueden compilar separadamente. Tipicamente ponemos las declaraciones que especifican la interface para un modulo en un archivo con un nombre que indica su uso. Por ejemplo:

```cpp
// Vector.h:
class Vector {
public:
Vector(int s);
double& operator[](int i);
int size();
private:
double∗ elem;
int sz;
};
```
Esta declaración se puede ubicar en un archivo `Vector.h` y los usuarios pueden incluir ese archivo, llamando al *header file* para acceder a el, por ejemplo:

```cpp
// user.cpp:
#include "Vector.h"
#include <cmath> // get Vector’s interface
// get the the standard-librar y math function interface including sqrt()
using namespace std; // make std members visible (§3.3)
double sqrt_sum(Vector& v)
{
    double sum = 0;
    for (int i=0; i!=v.siz e(); ++i)
    sum+=sqr t(v[i]);
    return sum;
}

```
## Namespaces

Para que no hayan conflictos con los nombres de los diferentes sources de un programa podemos encapsular los nombres propios en un namespaces propio

```cpp
namespace My_code {
        class complex {
        // ...
};
        complex sqr t(complex);
// ...
int main();
}
        int My_code::main()
{
        complex z {1,2};
        auto z2 = sqrt(z);
        std::cout << '{' << z2.real() << ',' << z2.imag() << "}\n";
// ...
};
int main()
{
        return My_code::main();
}
```
# Clases


La clase `complex` puede usarse :

```cpp
void f(complex z)
{
complex a {2.3};
// constr uct {2.3,0.0} from 2.3
complex b {1/a};
complex c {a+z∗complex{1,2.3}};
// ...
if (c != b)
c = −(b/a)+2∗b;
}
```
Donde vemos que se hace uso de los operadores que definimos anteriormente, como ser el operador `!=` o el operador `/`. Esto se conoce como sobrecarga de operadores. Esto se conoce como sobrecarga de operadores.

## Containers(contenedores)

Un *container* es un objeto que contiene una colección de elementos. Un vector como el que definimos antes puede ser un contenedor pero lo que nos falto agregar es poder deallocar la memoria utilizada, para ello existe en `C++` un mecanismo llamado `destructor` en nuestro caso sería:

```cpp
class Vector {
private:
double∗ elem;
// elem points to an array of sz doubles
int sz;
public:
Vector(int s) :elem{new double[s]}, sz{s}
// constr uctor: acquire resources
{
for (int i=0; i!=s; ++i)
// initialize elements
elem[i]=0;
}
 ̃Vector() { delete[] elem; }
// destr uctor: release resources
double& operator[](int i);
int size() const;
};

```
Siempre el nombre del destructor lleva adelante el operador complemento ` ̃`

###Inicializando contenedores

Necesitamos conocer los mecanismos con los cuales se extraen elementos de un
contenedor. Además de las clásicas(crear un vector e indexar el elemento) vamos
a ver otras dos maneras más elegantes:

    * *initializer-list constructor*: Inicializar con una lista de elementos
    * `push_back()`: Agregar un nuevo elemento al final de la secuencia.

Esto se puede declarar asi:

```cpp
class Vector {
public:
Vector(std::initializ er_list<double>);
// ...
void push_back(double);
// ...
};

```
`push_back` se puede utilizar para asignar un número arbitrario de elementos:

```cpp
Vector read(istream& is)
{
Vector v;
for (double d; is>>d;) // read floating point values into d
v.push_back(d); // add d to v
return v;
}

```
## Abstract types

types como `Vector` y `complex` son ejemplos de *concrete types*, porque su representación
es parte de de su definición. En contraste un *Abstract type* aisla completamente
del usuario los detalles de la implementación. Para hacer esto se desacopla la interface de
la representación. Podemos entonces escribir una version abstracta de nuestro `vector` que
nos puede servir para otros types parecidos.

```cpp
class Container {
public:
vir tual double& operator[](int) = 0; // pure virtual function
vir tual int size() const = 0; // const member function
vir tual  ̃Container() {} // destructor
};

```
la palabra *virtual* significa *va a definirse luego, en la clase derivada a esta*
La parte de código `= 0` significa que la función es toda virtual. Por ello una clase
 con solo funciones virtuales puras es una *Abstract Class*, esta clase puede ser
 utilizada de la siguiente manera:

 ```cpp
void use(Container& c)
{
    const int sz = c.size();
    for (int i=0; i!=sz; ++i)
    cout << c[i] << '\n';
}

 ```
 Notemos que `use()` utiliza a `Container` *inteface* ignorando completamente los
 detalles de la implementación. Además vemos que `Container` no posee constructor, y
 es natural ya que no posee datos con los que poder construir. `Container` podría utilizar
 la clase concreta `Vector`:

 ```cpp
class Vector_container : public Container { // Vector_container implements Container
    Vector v;
public:
    Vector_container(int s) : v(s) { }
// Vector of s elements
     ̃Vector_container() {}
    double& operator[](int i) { return v[i]; }
    int size() const { return v.siz e(); }
};

 ```
 La sentencia `:public` se puede leer como *es derivado de* o *es un subtype de*
 Para una función como `use(Container&)` usa a `Container` en completa ignorancia de los
 detalles de implementación. Si tuvieramos otra implementación de `Container`(Como una lista) no habría
 que cambiar nada de nuesto código en `use(Container&)`. Esto es posible ya que manipulamos al
 objeto mediante una Referencias a el.

 ## Funciones virtuales

 Consideremos de nuevo el uso de la clase `Container`:

 ```cpp
void use(Container& c)
{
    const int sz = c.size();
    for (int i=0; i!=sz; ++i)
         cout << c[i] << '\n';
}
```
Es lo que ya conocemos de herencia, cuando `use()` utiliza alguno de los métodos
de `Container` utiliza la implementación que pertenece a el objeto derivado.

## Herencia de Clases

Como vimos los ejemplos de la clase `Container` contenian Herencia a sus clases derivadas
Supongamos ahora que tenemos una clase:

`Shape` --> `Circle` --> `Smiley`

`Shape` --> `Triangle`

Para representar este diagrama en código, primero debemos especificar la clase que va a
especificar las propiedades más generales, osea la superclase `Shape`.


```cpp
	class Shape {
		public:
		vir tual Point center() const =0;
		vir tual void move(Point to) =0; // pure virtual

		vir tual void draw() const = 0;
		vir tual void rotate(int angle) = 0; // draw on current "Canvas"
		vir tual  ̃Shape() {} // ... // destr uctor

};

```
Naturalmente esta interface es una clase abstracta. Dada esta definición podemos escribir funciones generales que manipulen vectores de punteros a *shapes*

```cpp
void rotate_all(vector<Shape∗>& v, int angle) // rotate v’s elements by angle degrees
{
    for (auto p : v)
    p−>rotate(angle);
}
```
Luego podemos definir un *Shape* particular y especificar sus propiedades particulares:

```cpp
class Circle : public Shape {
public:
    Circle(Point p, int rr); // constructor
    Point center() const { return x; }
    void move(Point to) { x=to; }
    void draw() const;
    void rotate(int) {}
    private:
    Point x; // center
    int r; // radius

};
```
## Explicit overriding

Una función en una clase derivada sobreescribe una función virtual en la clase base si
la función tiene el mismo nombre y type. Para evitar confusiones en Herencias largas
el programador debe explicitar que esta sobreescribiendo una función base. Por ejemplo
si queremos sobreescribir la funciones de `Circle`:

```cpp
class Smiley : public Circle { // use the circle as the base for a face
public:
    Smiley(Point p, int r) : Circle{p,r}, mouth{nullptr} { }
     ̃Smiley()
    {
    delete mouth;
    for (auto p : eyes)
    delete p;
    }
    void move(Point to) override;
    void draw() const override;
    void rotate(int) override;
    void add_eye(Shape∗ s) { eyes.push_back(s); }
    void set_mouth(Shape∗ s);
    vir tual void wink(int i);
    // wink eye number i
// ...
    private:
    vector<Shape∗> eyes;
    Shape∗ mouth;
};
// usually two ey

```

Vemos que hemos agregado la palabra reservada `override`

## Copiando y moviendo

Por *default*, los objetos pueden ser copiados. La definición por *default* de copia
es que se copian elemento a elemento del objeto, por ejemplo:

```cpp
void test(complex z1)
{
    complex z2 {z1};
    complex z3;
    z3 = z2;
    // ...
}

```

Ahora `z1`, `z2` y `z3` tienen el mismo valor ya que ambos la asignación y la Inicialización
copian ambos miembros. Cuando diseñamos una clase, debemos especificar como y cuando se realiza
la copia del objeto.

## Copiando Containers

Cuando una clase maneja recursos(esto es que se accede a un objeto de ella a traves de un puntero)
la copia elemento a elemento no es una buena practica, por ejemplo:

```cpp
void bad_copy(Vector v1)
{
    Vector v2 = v1; // copy v1’s representation into v2
    v1[0] = 2; // v2[0] is now also 2!
    v2[1] = 3; // v1[1] is now also 3!
}

```
Copiar un objeto de una clase esta definido por dos miembros: *un constructor de copia*
y *una regla de asignación de copia*, por ejemplo:

```cpp
class Vector {
    private:
    double∗ elem; // elem points to an array of sz doubles
    int sz;
    public:
    Vector(int s); // constr uctor: establish invariant, acquire resources
     ̃Vector() { delete[] elem; } // destr uctor: release resources
    Vector(const Vector& a);
    Vector& operator=(const Vector& a); // copy constr uctor
    // copy assignment
    double& operator[](int i);
    const double& operator[](int i) const;
    int size() const;
};

```
Una adecuada manera de implementar el constructor es *allocate* para el numero de
elementos que queremos copiar y luego copiar los elementos dentro de el.

```cpp
Vector::Vector(const Vector& a) // copy constructor
    :elem{new double[a.sz]}, // allocate space for elements
sz{a.sz}
{
    for (int i=0; i!=sz; ++i) // copy elements
    elem[i] = a.elem[i];
}

```
Y además necesitamos un constructor para la operación de asignación:

```cpp
Vector& Vector::operator=(const Vector& a)
{
    double∗ p = new double[a.sz];
    for (int i=0; i!=a.sz; ++i)
    p[i] = a.elem[i];
    delete[] elem; // delete old elements
    elem = p;
    sz = a.sz;
    return ∗this;
}

```
La palabra reservada `this` es una función miembro que apunta al objeto que la
esta llamando.

## Moviendo contenedores

Podemos como vimos controlar todo el manejo de memoria cuando copiamos o asignamos
objetos, pero si los *containers* son grandes puede resultar costoso en recursos. Por
ello podemos evitar copiar cuando pasamos un *container* a una función pasando una
referencia de el, pero no podemos retornar una referencia a un objeto local como resultado
(el objeto local debe ser destruido por el tiempo en que es llamado ). Consideremos:

```cpp
Vector operator+(const Vector& a, const Vector& b)
{
    if (a.size()!=b.siz e())
    throw Vector_siz e_mismatch{};
    Vector res(a.size());
    for (int i=0; i!=a.size(); ++i)
    res[i]=a[i]+b[i];
    return res;
}

```
Devolviendo `res` de la definición anterior hace que se copie el resultado al
entorno que lo esta llamando, por ejemplo:

```cpp
void f(const Vector& x, const Vector& y, const Vector& z)
{
    Vector r;
    // ...
    r = x+y+z;
    // ...
}

```
Esto hace una copia de `Vector` almenos dos veces(una por cada uso del operador `+`).
Si el `Vector` es grande esteremos en problemas. Lo que debemos notar es que `res` en
`operator +()` no es utilizado nunca despues de ser copiado. Lo que queremos realmente
es mover al `Vector` antes de hacer una copia. Por suerte podemo hacerlo.

```cpp
class Vector {
    // ...
    Vector(const Vector& a); // copy constructor
    Vector& operator=(const Vector& a); // copy assignment
    Vector(Vector&& a); // move constructor
    Vector& operator=(Vector&& a); // move assignment
};

```
Dada esta definición el compilador elegirá el constructor para mover el `Vector`
en lugar del de copiar. Asi podemos definir el constructor de `Vector`:

```cpp
Vector::Vector(Vector&& a)
    :elem{a.elem},
    sz{a.sz}
{
    a.elem = nullptr;
    a.sz = 0;
}

```
El operador `&&` significa *rvalue reference*(rvalue: valor que puede ser asignado a derecha)
*rvalue* se puede pensar como un valor que nadie puede asignar, asi podemos retener
un valor que nos interese de manera segura.

#Templates

Un *template* es una clase o función que podemos parametrizar con un conjunto o
familia de *types* o valores.


##Parameterized Types

Podemos generalizar nuestro vector de `doubles` a un vector de cualquier *type*
que queramos, haciedo un *template* y reemplazando el parametro con el que necesecitemos


```cpp
template<typename T>
class Vector {
    private:
        T∗ elem; // elem points to an array of sz elements of type T
        int sz;
    public:
        explicit Vector(int s); // constructor: establish invariant, acquire resources
         ̃Vector() { delete[] elem; } // destructor: release resources
    // ... copy and move operations ...
        T& operator[](int i);
        const T& operator[](int i) const;
        int size() const { return sz; }
};

```

El prefijo `template<typename T>` hace a `T` como parametro, se puede ver como la
versión de `C++` de la sentencia matematica *para todo T*, o más precisamente *para
todo type T*. Las funciones miembro pueden ser definidas:

```cpp
template<typename T>
Vector<T>::Vector(int s)
{
    if (s<0)
    throw Negative_siz e{};
    elem = new T[s];
    sz = s;
}
template<typename T>
const T& Vector<T>::operator[](int i) const
{
    if (i<0 || size()<=i)
    throw out_of_rang e{"Vector::operator[]"};
    return elem[i];
}

```
Dadas estas definiciones podemos definir `Vector`es asi:

```cpp
Vector<char> vc(200); // vector of 200 characters
Vector<string> vs(17); // vector of 17 strings
Vector<list<int>> vli(45); // vector of 45 lists of integers

```
Si queremos los *fancy-for-loops* debemos agregar o sobreescribir las funciones
`begin()` y `end()`

```cpp
template<typename T>
T∗ begin(Vector<T>& x)
{
   return x.size() ? &x[0] : nullptr; // pointer to the first element or nullptr
}
template<typename T>
T∗ end(Vector<T>& x)
{
    return begin(x)+x.size(); // pointer to one-past-last element
}

```
Dadas estas definiciones podemos escribir:

```cpp
void f2(Vector<string>& vs)
{
    for (auto& s : vs)
    cout << s << '\n';
}

```
Además un *template* puede tomar como argumento un valor, por ejemplo:

```cpp
template<typename T, int N>
struct Buffer {
    using value_type = T;
    constexpr int size() { return N; }
T[N];
// ...
};

```
El alias `value_type` y la función `constexpr` son provistas para que el usuario
tenga acceso a los argumentos del *template*.
Tener valores como argumentos son muy utilies, por ejemplo `Buffer` nos permite
crear buffers de tamaño arbitrario sin malgastar los recursos de memoria(memoria dinamica)


```cpp
Buffer<char,1024> glob; // global buffer of characters (statically allocated)
void fct()
{
    Buffer<int,10> buf; // local buffer of integers (on the stack)
// ...
}

```
##Function Templates
Templates tienen muchos más usos que simplemente parametrizar *containers* con types
Por ejemplo podemos escribir una función que calcule la suma de todos los elementos
de cualquier *container* :

```cpp
template<typename Container, typename Value>
Value sum(const Container& c, Value v)
{
    for (auto x : c)
    v+=x;
    return v;
}
```
Por ello cada vez que utilicemos la función `sum()` no necesitaremos explicitar 
los *types* ya que lo hace automaticamente el compilador. Un ejemplo de uso sería:

```cpp
 void user(Vector<int>& vi, std::list<double>& ld, std::vector<complex<double>>& vc)
{
    int x = sum(vi,0);
    // the sum of a vector of ints (add ints)
    double d = sum(vi,0.0);
    // the sum of a vector of ints (add doubles)
    double dd = sum(ld,0.0);
    // the sum of a list of doubles
    auto z = sum(vc,complex<double>{}); // the sum of a vector of complex<double>
    // the initial value is {0.0,0.0}
}
```
## Programación generica

Cuales son los beneficios de utilizar Templates???

    * La posibilidad de pasar *types* como argumentos, sim perder información
    * Retrasar el chequeo de *types*. Esto implica la posibilidad de mezclar información de diferentes contextos
    * La posibilidad de pasar valores constante como argumentos. Esto da la posibilidad de hacer calculos en tiempo
    de compilación. 

## Function Objects

Un template particularmente útil es el *function object* (llamado también *functor*)
el cual es usado para definir objetos que pueden ser llamados como funciones. Por ejemplo:

```cpp
template<typename T>
class Less_than {
    const T val; // value to compare against
    public:
    Less_than(const T& v) :val(v) { }
    bool operator()(const T& x) const { return x<val; } // call operator
};

```
Esta función llamada `operator()` implementa la llamada a la "función" del operador `()`
Podemos definir variables de nombres de *type* `Less_than` para algún argumento(de algún *type*)
Los *functors* son utilizados para especificar el significado de las operaciones fundamentales de un algoritmo general.

```cpp
Less_than<int> lti {42}; // lti(i) will compare i to 42 using < (i<42)
Less_than<string> lts {"Backus"}; // lts(s) will compare s to "Backus" using < (s<"Backus")

```
Y podríamos llamar a estos *functors* como:

```cpp
void fct(int n, const string & s)
{
    bool b1 = lti(n); // tr ue if n<42
    bool b2 = lts(s); // tr ue if s<"Backus"
    // ...
}

```
Asi estos *functors* son ampliamente utilizados como argumento de *algorithms*. 
Por ejemplo podemos contar las ocurrencias de un valor para el cual un predicado 
retorna `true` :

```cpp
template<typename C, typename P>
int count(const C& c, P pred)
{
    int cnt = 0;
    for (const auto& x : c)
    if (pred(x))
    ++cnt;
    return cnt;
}

```
Y un predicado lo podemos modelar como algo que invocamos y retorna `true` o `false`

```cpp
void f(const Vector<int>& vec, const list<string>& lst, int x, const string& s)
{
    cout << "number of values less than " << x
    << ": " << count(vec,Less_than<int>{x})
    << '\n';
    cout << "number of values less than " << s
    << ": " << count(lst,Less_than<string>{s})
    << '\n';
}

```
El único inconveniente es que debemos definir separadamente a `Less_than`, pero 
por suerte existe una manera de hacerlo *inline* :

```cpp
void f(const Vector<int>& vec, const list<string>& lst, int x, const string& s)
{
    cout << "number of values less than " << x
    << ": " << count(vec,[&](int a){ return a<x; })
    << '\n';
    cout << "number of values less than " << s
    << ": " << count(lst,[&](const string& a){ return a<s; })
    << '\n';
}

```
La notación `[&](int a){return a<x;}` es llamada *lambda expression* y genera un 
objeto exactamente igual a `Less_than<int>{}`. El `[&]` se llama *capture list*
especificando que las variables locales van a ser accedidas por refencias, también como 
solo queríamos `x` podríamos haber escrito `[&x]`, si hubieramos querido una copia de `x`
podríamos haber escrito `[=x]`, capturar nada es `[]`, capturar todos los nombres `[]` y 
capturar todos los nombres capturados por valor `[=]`. 


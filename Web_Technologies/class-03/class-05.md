# Creating app 

`rails new library -d postgresql -j esbuild --css bootstrap`

## Database
- book
> - pk id
> - title: string
> - year: int


- author
> - pk id
> - name: string
> - last_name: string
> - birthdate: date
> - blood: int


 App -> modelos, clase(codigo): singular
> - book, PascalCase

DB -> tablas: plural
> - books, snake_case

luego de crear proyecto, primero crear tablas.
primero crear base de datos, `config/database.yml development:`
en terminal correr `bin/ails db:create`
- `library_development`
- `library_test`

### 1. Creación de tabla
rails tiene ORM, se escribe ruby no SQL. 
- `bin/rails generate migration CreateBooksTable`
- `bin/rails g migration CreateBooksTable`

dentro de change`/db/migrate/2024....rb`
```
def change
    create_table :books do |t|
        t.string :title
        t.integer :year_of_publication

        t.timestamps 
    end
end
```
siempre tener un create table por migración
- `t.timestamps` crea `created_at, updated_at`

luego ir a terminal: `bin/rails db:migrate`

### 2. Modelo
psql -d postgres
\c library_development
\dt

ahora en: `/app/models/book.rb`:

```
class Book < ApplicationRecord

end
```
luego en terminal `bin/rails console` o `bin/rails c`
- `Book.all`
- `Book` muestra lo que hay
- `book = Book.new(title: '12 Reglas para vivir', year_of_publication: 2010)` crear una variable, pero no se guarda en la db
- `book` muestra datos de la variable
- `book.persisted?` confirma si esta creado o no en la db
- `book.save` decirle guardar en la db, hace el insert
- `Book.all` select from books, and will show the elements
- `Book.find 8` u give it the id

Guardar de inmediato en db:
- `Book.create(title:'Papelucho', year_of_publication: 1947)` se puede hacer al mismo tiempo

no puede haber libro sin titulo, si quiero modificar algo en la migración hay que crear una nueva.

### 3. Validaciones
Podemos tener validaciones en el modelo, ej, que title no sea null (a nivel de modelo, no db)
```
class Book < ApplicationRecord
    validates :title, presence: true
    validates :year_of_publication, presence: true
end
```
Cambiar algo en el modelo
- `reload!`
- `b = Book.new`
- `b.save` false or `b.save!`
- `b.valid?` confirma y revisa las validaciones del modelo

Cambiarlo en la base de datos: hay que hacer otra migracion
- `quit`
- `bin/rails g migration RequiredFieldsInBooks`
````
class RequiredFieldsInBooks < Active...
    def change
        change_column_null :books, :title, false
    end
end
````
- ejecutar migracion `db migrate` ahora el modelo va a cambiar 
solo cuando quiero modificar la ultima migracion se puede hacer
````
class RequiredFieldsInBooks < Active...
    def change
        change_column_null :books, :title, false
        change_column_null :books, :year_of_publication, false
    end
end
````
- `db redo`
- `bin/drop`
- ``
luego al crear la tabla denuevo se ejecutan las migraciones en orden:3
- `bin/rails`
- `Book.all`

### 4. Seeds
al clonar repo, va a salir vacio, pero aqui vienen los seeds `db/seeds.rb`
```
Book.create!(title: '12 Reglas para vivir', year_of_publication: 2010)
Book.create!(title:'Papelucho', year_of_publication: 1947)
```
para fechas hacy que hacer esto: `'birth_date: Date.new(1956, 09, 02)'`
siempre en los seeds poner `!`
- `bin/rails db:seed`
- `bin/rails`
- `Book.all`
saldran todos los de la seed 


no permitir mismos libro con mismo titulo:
```
class Book < ApplicationRecord
    validates :title, presence: true, uniqueness: true
    validates :year_of_publication, presence: true
end
```
`bin/rails db:seed` va a fallar porque tienen mismo titulo

mejor ponerle:
```
Book.delete_all
Book.create!(title: '12 Reglas para vivir', year_of_publication: 2010)
Book.create!(title:'Papelucho', year_of_publication: 1947)
```
para que deje correr de nuevo los seeds, pero va a perder los id del principio, son autoincrementales. Para que empiece de 0 de nuevo hay que borrar la tabla.
- `git status`
- `git add .`
- `git commit -m "crear tabla, modelo y seed para libros"``

## Resumen
1. Crear tabla
2. Modelo
3. Validaciones (todo not null)
4. Seed

en el modelo abajo de los validates se puede hacer un hash con un enum, para hacer equivalencias de nuemeros a claves. 

action text para textos largos `hash_rich_text :content`

## Clase 6

create the router, the class controller
`get '/books', to: 'books#index'`
```
class BooksController < ApplicationController
    def index
        @books = Book.all

    end
end
```
en layouts debe estar plural. `books/index.html.rb` Div container agrega la responsividad y los margenes. Meter todo dentro de un container en el layout. Meter el yield en `div.container`

@variable es global entonces estan disponibles en la vista.

luego en la vista (index.html.rb)
```
<ul>
<% @books.each do |book| %>
    <li><%= book.title %>: <%= book.year_of_publication %></li>
    <p><%= link_to book.title, book_path(book)%></p>
    <p><%= link_to 'Ver', book_path(book)%></p>
    <%end%>
</ul>
```

CRUD-> READ->listar(index), ver(show)
routes
```
get 'routes/:id', to: 'books#show'
```

luego en Books controller: 
```
class BooksController < ApplicationController
    def index
        @books = Book.all

    end
    def show
        @book = Book.find params['id']
    end
end
```
luego en vista `show.html.rb`
```
<h1><%= @book.title %></h1>
```

en routes atajo: crea todas las rutas de una: 
`resources books`

### Asociaciones
- como relacionamos las dos tablas. En este caso 1.N.
- en book hacer llave foranea `fk author_id`

Entonces hay que hacer una migración. 
`bin/railes g migrations addAuthortoBook`
```
class AddAuthortoBook
    def change
        change_table :books do |t|
            t.belongs_to :author, foreign_key: true
        end
    end
end
```
esto modificara el esquema al hacer `migrate`

en el modelo igual hay que hacer el coso:
```
class Book 
    belongs_to :author
    ...
    validates
end
```
```
class author
    has_many :books
    ... 
    validates
end
```

en los seeds habrá que agregar eso. 

`peterson = Author.create!(....)`

`Book.create!(....., author_id: peterson.id)`

`Book.create!(....., author: peterson)`

Luego será posible hacer algo asi
`Book.first.author.name`

en el modelo se pueden definir metodos por ejemplo para hacer el nombre entero y no separado name y last name

## Clase 7
before_validation
after_validation
before_save
after_save

Active record cllbacks ruby on rails https://guides.rubyonrails.org/active_record_callbacks.html#creating-an-object

```
Class Author
    def full_name
        "#{name} #{last_name}
    end
    private
    def titelize name

```

Create from CRUD, gonna use a formulario
- books_controller.rb
```
def new
    @book = Book.new
end
def create
    book = Book.new book_params
    if book.save
        redirect_to book_path(book)
    else
        redirect_to :new_book_path
    end 
end
private
    def books_params
        params.requite(:books).permit(:title, :year_of_publication)
```
new.html.erb
```
div "container
    <%= form_with: model @book do |form| %>
    <%= form.label :title, 'Titulo' %>
    <%= form.text_field :title %>
    <%= form.label :title, 'Titulo' %>
    <%= form.date_field :date_of_publication %>
    <%= form.sumbit 'Guardar'%>
    <% end %>
</div>
```
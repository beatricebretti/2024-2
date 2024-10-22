# Autenticación

gema para ruby autenticar: _devise_ `bundle add devise`

rails generate devise MODEL
- model puede ser lo que sea, del modelo de usuario 

correr migración 

se deben modificar los controladores, callback de los controladores, en app controles agregar `before action....`

agregar botón salir `if user_signed_in?` and `destroy_user_session_path, data:{turbo_method: :delete}`

cambiar vista del login: `rails generate devise:views`

se pueden administrar diferentes permisos, la linea de before action se puede agregar en cada controlador o para todo en app controller. En post controler se puede poner `before_action: auth..., except: [:index, :view]`

# Autorización
Permisos y restringir. _cancancan_

`bundle add cancancan`

Abilities clase que tendrá los permisos. `rails g cancan:ability` or something (ver documentacion).

add this callback
`load_and_authorize_resource` o `authorize_resouce` ver documentacion

/model/ability.rb:
```
def initializa(user)
    can :read, Post
    can :update, Post, user_id: user.id
    or 
    can :manage, Post, user: user
```
relacionar post con usuario con migracion.

`g migration BackFillPostsUsers`para completar anteriorees post sin usuario

Al hacer cambio en ability reiniciar servidor

borrar boton editar si no tiene permiso 
```
<%if can?(:edit, post)%>
mostrar boton
```


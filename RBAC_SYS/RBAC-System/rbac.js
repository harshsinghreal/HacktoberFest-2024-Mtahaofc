//defining role class to manage permissions dynamically
function Role(name){
    this.name = name;
    this.permissions = {};
}
//add a method for assigning permissions for diff actions and resoursces
Role.prototype.addPermission = function(action, resource){
    if(!this.permissions[resource]){
        this.permissions[resource] = [];
    }
    if(!this.permissions[resource].includes(action)){
        this.permissions[resource].push(action);
    }
}
//checking if role has the specific action from that specific resource
Role.prototype.hasPermission = function(action, resource){
    return this.permissions[resource].includes(action) && this.permissions[resource];
}
//creating a user class that can have multiple roles
function User(name){
    this.name = name;
    this.roles = [];
}
//adding roles to the User
User.prototype.addRole = function(role){
    this.roles.push(role);
}

//check if a user has permission for a specific action on a resource
User.prototype.can = function(action, resource){
    return this.roles.some(role => role.hasPermission(action, resource));
}

//define some roles
const adminRole = new Role("Admin");
adminRole.addPermission("read", "posts");
adminRole.addPermission("write", "posts");
adminRole.addPermission("delete", "posts");
adminRole.addPermission("manage", "users"); // Admin can manage users

const editorRole = new Role("Editor");
editorRole.addPermission("read", "posts");
editorRole.addPermission("write", "posts");

const guestRole = new Role("Guest");
guestRole.addPermission("read", "posts");

// Step 4: Create users and assign them roles
const alice = new User("Alice");
alice.addRole(adminRole); // Alice is an Admin

const bob = new User("Bob");
bob.addRole(editorRole); // Bob is an Editor

const charlie = new User("Charlie");
charlie.addRole(guestRole); // Charlie is a Guest

// Step 5: Demonstration
console.log(`${alice.name} can manage users:`, alice.can("manage", "users"));  // true
console.log(`${bob.name} can delete posts:`, bob.can("delete", "posts"));  // false
console.log(`${charlie.name} can read posts:`, charlie.can("read", "posts"));  // true
console.log(`${charlie.name} can write posts:`, charlie.can("write", "posts"));  // false
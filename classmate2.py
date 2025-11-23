
class Classmate:
    
    def __init__(self, name, age, hobby, gender, skin_color, height):

        self.name = name
        self.age = age
        self.hobby = hobby
        self.gender = gender
        self.skin_color = skin_color
        self.height = height
    
    def display_info(self):
        print("\n--- Classmate Information ---")
        print(f"Name: {self.name}")
        print(f"Age: {self.age}")
        print(f"Hobby: {self.hobby}")
        print(f"Gender: {self.gender}")
        print(f"Skin Color: {self.skin_color}")
        print(f"Height: {self.height}")


classmate1 = Classmate("michael", 17, "playing football", "male", "brown", "6ft")
classmate1.display_info()
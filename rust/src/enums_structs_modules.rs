/** examples for enums, structs, modules and submodules */
pub fn run_examples() {

    struct CatID {
        birth_year: u16
    }

    enum Cat {
        Alive {
            is_hungry: bool,
            wants_to_play: bool,
            id: CatID
        },
        Dead {
            id: CatID,
            death_year: u16
        }
    }

    let cat_id: CatID = CatID { birth_year: 2015 };
    // declare and assign mutable dead cat
    let cat: Cat = Cat::Dead { id: cat_id, death_year: 2022 };

}

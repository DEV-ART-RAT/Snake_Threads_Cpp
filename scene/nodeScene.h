/** Data estructure that saves intructions to design an stage
* row y col refers to porcentual initial position ([0-10])
* end its the final position 
* direction verifies if is refering to a row or a column
*/
struct sceneInfo{
    int row;
    int col;
    int end;
    bool direction;

    //Constructors
    sceneInfo(){}
    sceneInfo(int r, int c, int e,bool d): row(r),col(c),end(e),direction(d){}

    //Overloads
    
    bool operator==(const sceneInfo& r) {
        return 
        this->row == r.row 
        && this->col == r.col 
        && this->end == r.end; 
    }

    bool operator!=(const sceneInfo& r) {
        return 
        this->row != r.row 
        && this->col != r.col 
        && this->end == r.end; 
    }

    //Functions
    
    bool comparate(sceneInfo& r,int flag){
        if(flag == 1){
            return this->row >= r.row;
        }
        if(flag == 2){
            return this->col >= r.col;
        }
        if(flag == 3){
            return this->end >= r.end;
        }
    }

    string getDirection(){
        return (direction)? "fila ":" columna ";
    }

    friend ostream& operator<<(ostream& os, const sceneInfo& p) {
        string d = (p.direction)? "fila ":" columna ";
        os << 
        "{row%: " +to_string(p.row) +
        ": col%: "+ to_string(p.col) +
        ": end%: "+ to_string(p.end) +
        ": direction: "+ d +
        "}";
        return os;
    }
};

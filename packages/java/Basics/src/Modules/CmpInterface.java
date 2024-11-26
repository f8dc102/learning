import java.util.Comparator;

class Student implements Comparator<Student> {
  int age, classNumber;

  Student(int age, int classNumber) {
    this.age = age;
    this.classNumber = classNumber;
  }

  @Override
  public int compare(Student o1, Student o2) {
    if (o1.classNumber > o2.classNumber) {
      return 1;
    } else if (o1.classNumber == o2.classNumber) {
      return 0;
    } else {
      return -1;
    }
  }
}

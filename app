import java.awt.*;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import javax.swing.*;
import java.util.Optional;

class Student {
    String name, id, section, department, dob, phone, email, address, enrollmentDate;
    ArrayList<String> courses = new ArrayList<>();
    ArrayList<Double> creditHours = new ArrayList<>();
    ArrayList<Integer> scores = new ArrayList<>();
    ArrayList<String> grades = new ArrayList<>();
    double gpa, sgpa;

    public Student(String name, String id, String section, String department, String dob, String phone, String email, String address, String enrollmentDate) {
        this.name = name;
        this.id = id;
        this.section = section;
        this.department = department;
        this.dob = dob;
        this.phone = phone;
        this.email = email;
        this.address = address;
        this.enrollmentDate = enrollmentDate;
    }

    public void addCourse(String course, double creditHour, int score) {
        courses.add(course);
        creditHours.add(creditHour);
        scores.add(score);
        grades.add(calculateGrade(score));
        calculateGPA();
        calculateSGPA();
    }

    public String calculateGrade(int score) {
        if (score >= 90) return "A";
        if (score >= 80) return "B";
        if (score >= 70) return "C";
        if (score >= 60) return "D";
        return "F";
    }

    public double calculateGPA() {
        double totalGradePoints = 0;
        double totalCreditHours = 0;
        for (int i = 0; i < courses.size(); i++) {
            double gradePoint;
            switch (grades.get(i)) {
                case "A": gradePoint = 4.0; break;
                case "B": gradePoint = 3.0; break;
                case "C": gradePoint = 2.0; break;
                case "D": gradePoint = 1.0; break;
                default: gradePoint = 0.0; break;
            }
            totalGradePoints += gradePoint * creditHours.get(i);
            totalCreditHours += creditHours.get(i);
        }
        gpa = totalCreditHours > 0 ? totalGradePoints / totalCreditHours : 0;
        return gpa;
    }

    public double calculateSGPA() {
        // Implement semester-specific GPA logic if needed
        sgpa = gpa; // Example logic
        return sgpa;
    }

    public String toString() {
        return "Name: " + name + ", ID: " + id + ", GPA: " + gpa + "\n";
    }
}

public class GradeManagementApp {
    private static ArrayList<Student> students = new ArrayList<>();

    public static void main(String[] args) {
        SwingUtilities.invokeLater(GradeManagementApp::createGUI);
    }

    private static void createGUI() {
        JFrame frame = new JFrame("Grade Management System");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(400, 300);
        frame.setLayout(new FlowLayout());

        JButton addButton = new JButton("Add Student");
        addButton.addActionListener(e -> addStudentDialog(frame));

        JButton viewButton = new JButton("View Students");
        viewButton.addActionListener(e -> viewStudentsDialog(frame));

        JButton searchButton = new JButton("Search Student");
        searchButton.addActionListener(e -> searchStudentDialog(frame));

        JButton exportButton = new JButton("Export Data");
        exportButton.addActionListener(e -> exportStudentData());

        frame.add(addButton);
        frame.add(viewButton);
        frame.add(searchButton);
        frame.add(exportButton);

        frame.setVisible(true);
    }

    private static void addStudentDialog(JFrame frame) {
        JTextField nameField = new JTextField(10);
        JTextField idField = new JTextField(10);
        JTextField sectionField = new JTextField(10);
        JTextField departmentField = new JTextField(10);

        JPanel panel = new JPanel();
        panel.add(new JLabel("Name:"));
        panel.add(nameField);
        panel.add(new JLabel("ID:"));
        panel.add(idField);
        panel.add(new JLabel("Section:"));
        panel.add(sectionField);
        panel.add(new JLabel("Department:"));
        panel.add(departmentField);

        int result = JOptionPane.showConfirmDialog(frame, panel, "Add Student", JOptionPane.OK_CANCEL_OPTION);
        if (result == JOptionPane.OK_OPTION) {
            String name = nameField.getText();
            String id = idField.getText();
            String section = sectionField.getText();
            String department = departmentField.getText();

            Student student = new Student(name, id, section, department, "01/01/2000", "", "", "", "01/01/2021");
            students.add(student);
            JOptionPane.showMessageDialog(frame, "Student added successfully!");
        }
    }

    private static void viewStudentsDialog(JFrame frame) {
        StringBuilder sb = new StringBuilder();
        for (Student student : students) {
            sb.append(student).append("\n");
        }

        JTextArea textArea = new JTextArea(15, 25);
        textArea.setText(sb.toString());
        textArea.setEditable(false);

        JOptionPane.showMessageDialog(frame, new JScrollPane(textArea), "All Students", JOptionPane.PLAIN_MESSAGE);
    }

    private static void searchStudentDialog(JFrame frame) {
        String id = JOptionPane.showInputDialog(frame, "Enter Student ID or Name:");
        if (id == null || id.trim().isEmpty()) {
            JOptionPane.showMessageDialog(frame, "Search query cannot be empty!");
            return;
        }

        Optional<Student> student = students.stream()
                .filter(s -> s.id.equalsIgnoreCase(id) || s.name.equalsIgnoreCase(id))
                .findFirst();

        if (student.isPresent()) {
            JOptionPane.showMessageDialog(frame, "Student Found:\n" + student.get());
        } else {
            JOptionPane.showMessageDialog(frame, "Student not found!");
        }
    }

    private static void exportStudentData() {
        try (FileWriter writer = new FileWriter("students_data.txt")) {
            for (Student student : students) {
                writer.write(student.toString());
            }
            JOptionPane.showMessageDialog(null, "Data exported successfully to 'students_data.txt'");
        } catch (IOException e) {
            JOptionPane.showMessageDialog(null, "Failed to export data: " + e.getMessage());
        }
    }
}

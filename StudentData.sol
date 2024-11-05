// SPDX-License-Identifier: MIT
pragma solidity ^0.8.0;

contract StudentManagement 
    { 
    struct Student 
        {
        uint256 id;
        string name;
        uint256 age;
        string course;
        }

    Student[] public students;
    event StudentAdded(uint256 id, string name, uint256 age, string course);
    
    fallback() external payable 
        {
        // You can log or handle unexpected Ether or data sent to this contract.
        }

    receive() external payable 
        {
        // This function is triggered when Ether is sent without any data.
        }

    function addStudent(uint256 _id, string memory _name, uint256 _age, string memory _course) public
        {
        Student memory newStudent = Student({
            id: _id,
            name: _name,
            age: _age,
            course: _course
        });
        students.push(newStudent);
        emit StudentAdded(_id, _name, _age, _course);
        }

    function getStudentCount() public view returns (uint256) 
        {
        return students.length;
        }

    function getStudent(uint256 index) public view returns (uint256, string memory, uint256, string memory) 
        {
        require(index < students.length, "Student does not exist.");
        Student memory s = students[index];
        return (s.id, s.name, s.age, s.course);
        }
    }

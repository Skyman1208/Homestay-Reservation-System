-- phpMyAdmin SQL Dump
-- version 4.9.0.1
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: Mar 22, 2020 at 04:42 AM
-- Server version: 10.3.16-MariaDB
-- PHP Version: 7.3.7

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET AUTOCOMMIT = 0;
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `hms_db`
--

-- --------------------------------------------------------

--
-- Table structure for table `bill_record`
--

CREATE TABLE `bill_record` (
  `BillID` int(11) NOT NULL,
  `ReservationID` int(11) NOT NULL,
  `B_Charge` decimal(50,2) NOT NULL,
  `B_NumOfDays` int(3) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `bill_record`
--

INSERT INTO `bill_record` (`BillID`, `ReservationID`, `B_Charge`, `B_NumOfDays`) VALUES
(1, 6, '28.00', 28),
(2, 7, '250.00', 5);

-- --------------------------------------------------------

--
-- Table structure for table `customer_record`
--

CREATE TABLE `customer_record` (
  `CustomerID` int(5) NOT NULL,
  `C_Name` varchar(100) NOT NULL,
  `C_Address` varchar(100) NOT NULL,
  `C_PhoneNo` varchar(15) NOT NULL,
  `C_Email` varchar(50) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `customer_record`
--

INSERT INTO `customer_record` (`CustomerID`, `C_Name`, `C_Address`, `C_PhoneNo`, `C_Email`) VALUES
(1, 'Ali Bin Abu', 'Taman UiTM Kenanga', '021-123456789', 'ali@gmail.com'),
(2, 'ali baba', 'sdfihf', '876543', 'f wfc'),
(3, 'edq', 'qwe', 'wq', 'wq'),
(4, 'dfs', 'dsfc', '32', 'fdsc'),
(5, 'haziq', 'tgrefds', '234242', 'egvefrf'),
(6, 'haziq', 'wfwwe', '4321', 'dcscs'),
(7, 'haziq', 'da', '3', 'rfe'),
(8, 'haziq', 'fddfs', '32432', 'dfvfvd'),
(9, 'qwe', 'qew', '123', 'qew'),
(10, 'adsa', 'adsasad', '13131', 'adsads'),
(11, 'qweeq', 'qweqwe', '123', 'qweqe'),
(12, 'qweqwew', 'qewqewqe', '12313', 'qweweqe'),
(13, 'qweqqw', 'qeeq', 'qeeqqe', 'wqweqe'),
(14, 'qweqew', 'qweqwe', '12312', 'qwewqe'),
(15, 'azri', 'adaddda', '123132', 'adffsf'),
(16, 'syam', 'wqeqeq', '11313', 'adsdad'),
(17, 'c', 'c', 'c', 'c'),
(18, '1', '1', '1', '1'),
(19, '10', '10', '10', '10'),
(20, 'a', 'a', 'a', 'a'),
(21, 'e', 'e', 'e', 'e');

-- --------------------------------------------------------

--
-- Table structure for table `homestay_record`
--

CREATE TABLE `homestay_record` (
  `HomestayID` int(5) NOT NULL,
  `H_Name` varchar(100) NOT NULL,
  `H_Price` decimal(50,2) NOT NULL,
  `H_Pool` varchar(15) NOT NULL,
  `H_Type` varchar(20) NOT NULL,
  `H_NumOfRoom` int(11) NOT NULL,
  `H_NumOfBed` int(11) NOT NULL,
  `H_NumOfToilet` int(11) NOT NULL,
  `H_Aircond` varchar(20) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `homestay_record`
--

INSERT INTO `homestay_record` (`HomestayID`, `H_Name`, `H_Price`, `H_Pool`, `H_Type`, `H_NumOfRoom`, `H_NumOfBed`, `H_NumOfToilet`, `H_Aircond`) VALUES
(1, 'SATRIA LEKIR', '1.00', 'Yes', 'Family', 8, 8, 8, 'No'),
(7, 'SATRIA TUAH', '50.00', 'Yes', 'Couple', 6, 2, 0, 'Yes'),
(8, 'SATRIA KASTURI', '50.00', 'No', 'Single', 2, 10, 3, 'No'),
(9, 'SATRIA JEBAT', '400.00', 'Yes', 'Couple', 2, 2, 2, 'Yes'),
(10, 'SATRIA LEKIU', '49.00', 'No', 'Couple', 2, 0, 4, 'No'),
(13, 'LESTARI KASTURI', '250.00', 'Yes', 'Single', 2, 2, 2, 'Yes'),
(14, 'LESTARI LEKIU', '200.00', 'No', 'Single', 2, 2, 2, 'No'),
(15, 'LEKIU TUAH', '500.00', 'Yes', 'Couple', 2, 2, 2, 'No'),
(16, 'LEKIU SATRIA', '900.00', 'No', 'Couple', 4, 8, 3, 'Yes');

-- --------------------------------------------------------

--
-- Table structure for table `reservation_record`
--

CREATE TABLE `reservation_record` (
  `ReservationID` int(5) NOT NULL,
  `HomestayID` int(5) NOT NULL,
  `StaffID` int(11) NOT NULL,
  `CustomerID` int(11) NOT NULL,
  `R_CheckInDate` varchar(10) NOT NULL,
  `R_CheckOutDate` varchar(10) DEFAULT NULL,
  `Status` varchar(10) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `reservation_record`
--

INSERT INTO `reservation_record` (`ReservationID`, `HomestayID`, `StaffID`, `CustomerID`, `R_CheckInDate`, `R_CheckOutDate`, `Status`) VALUES
(6, 1, 7, 17, '2020-02-20', '2020-03-20', 'RESERVED'),
(7, 7, 7, 21, '2020-03-30', '2020-04-04', 'RESERVED');

-- --------------------------------------------------------

--
-- Table structure for table `staff_record`
--

CREATE TABLE `staff_record` (
  `StaffID` int(5) NOT NULL,
  `S_Name` varchar(100) NOT NULL,
  `S_PhoneNo` varchar(15) NOT NULL,
  `S_Password` varchar(50) NOT NULL,
  `S_Type` varchar(5) NOT NULL,
  `S_Email` varchar(50) NOT NULL,
  `S_Address` varchar(100) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `staff_record`
--

INSERT INTO `staff_record` (`StaffID`, `S_Name`, `S_PhoneNo`, `S_Password`, `S_Type`, `S_Email`, `S_Address`) VALUES
(3, 'aiman', '011-12345678', '12345', 'admin', 'aiman@gmail.com', 'Taman UTeM Kasturi'),
(7, 'din mano', '09876543', '123', 'user', 'din@gmail.com', 'hgfds'),
(9, 'syam', '5432', ' ', 'user', 'sdf', 'sdf'),
(10, 'azri', '42', 'sdfd', 'user', 'ds', 'dsx'),
(11, 'jabon', '443', '123', 'user', 'gfds', 'gfvdc'),
(12, '33', '3', '33', 'user', '3', '3'),
(123, 'izzboy', '012-123456789', '123', 'admin', 'izzboy@gmail.com', 'Taman UTeM Kasturi'),
(124, 'arif', '23123131', '123', 'user', 'weqeqwe', 'qweqweq'),
(125, 'ppoiu', '0987', 'poiu', 'user', 'poiu', 'poiu'),
(126, 'LALALA', '01924314323', '123', 'admin', 'LALALA', 'alallalala'),
(127, 'Faris Tamrulan', '0192880404', '123', 'user', 'FarisTam@gmail.com', 'JDT '),
(130, 'a', 'a', 'a', 'user', 'a', 'a'),
(131, 'b', 'b', 'b', 'user', 'b', 'b');

--
-- Indexes for dumped tables
--

--
-- Indexes for table `bill_record`
--
ALTER TABLE `bill_record`
  ADD PRIMARY KEY (`BillID`),
  ADD KEY `B_ReservationID` (`ReservationID`);

--
-- Indexes for table `customer_record`
--
ALTER TABLE `customer_record`
  ADD PRIMARY KEY (`CustomerID`);

--
-- Indexes for table `homestay_record`
--
ALTER TABLE `homestay_record`
  ADD PRIMARY KEY (`HomestayID`);

--
-- Indexes for table `reservation_record`
--
ALTER TABLE `reservation_record`
  ADD PRIMARY KEY (`ReservationID`),
  ADD KEY `CustomerID` (`CustomerID`),
  ADD KEY `HomestayID` (`HomestayID`),
  ADD KEY `StaffID` (`StaffID`);

--
-- Indexes for table `staff_record`
--
ALTER TABLE `staff_record`
  ADD PRIMARY KEY (`StaffID`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `bill_record`
--
ALTER TABLE `bill_record`
  MODIFY `BillID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=3;

--
-- AUTO_INCREMENT for table `customer_record`
--
ALTER TABLE `customer_record`
  MODIFY `CustomerID` int(5) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=22;

--
-- AUTO_INCREMENT for table `homestay_record`
--
ALTER TABLE `homestay_record`
  MODIFY `HomestayID` int(5) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=19;

--
-- AUTO_INCREMENT for table `reservation_record`
--
ALTER TABLE `reservation_record`
  MODIFY `ReservationID` int(5) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=8;

--
-- AUTO_INCREMENT for table `staff_record`
--
ALTER TABLE `staff_record`
  MODIFY `StaffID` int(5) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=132;

--
-- Constraints for dumped tables
--

--
-- Constraints for table `reservation_record`
--
ALTER TABLE `reservation_record`
  ADD CONSTRAINT `reservation_record_ibfk_1` FOREIGN KEY (`CustomerID`) REFERENCES `customer_record` (`CustomerID`),
  ADD CONSTRAINT `reservation_record_ibfk_3` FOREIGN KEY (`StaffID`) REFERENCES `staff_record` (`StaffID`),
  ADD CONSTRAINT `reservation_record_ibfk_4` FOREIGN KEY (`HomestayID`) REFERENCES `homestay_record` (`HomestayID`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;

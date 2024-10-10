
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

// Lớp cơ sở cho tất cả các sản phẩm
class SanPham {
protected:
    std::string ten;
    int soLuong;
    std::string ngaySanXuat;
    std::string hanSuDung; // Thêm hạn sử dụng

public:
    SanPham(const std::string& ten, int soLuong, const std::string& ngaySanXuat, const std::string& hanSuDung);
    
    virtual void inThongTin() const;
    void themSanPham(int soLuong);
    bool banSanPham(int soLuong);
};

// Lớp con cho thịt
class Thit : public SanPham {
private:
    std::string loaiThit;

public:
    Thit(const std::string& ten, int soLuong, const std::string& ngaySanXuat, const std::string& hanSuDung, const std::string& loaiThit);
    void inThongTin() const override;
};

// Lớp con cho cá
class Ca : public SanPham {
private:
    std::string loaiCa;

public:
    Ca(const std::string& ten, int soLuong, const std::string& ngaySanXuat, const std::string& hanSuDung, const std::string& loaiCa);
    void inThongTin() const override;
};

// Lớp con cho kẹo
class Keo : public SanPham {
private:
    std::string loaiKeo;

public:
    Keo(const std::string& ten, int soLuong, const std::string& ngaySanXuat, const std::string& hanSuDung, const std::string& loaiKeo);
    void inThongTin() const override;
};

// Lớp con cho nước
class Nuoc : public SanPham {
private:
    std::string loaiNuoc;

public:
    Nuoc(const std::string& ten, int soLuong, const std::string& ngaySanXuat, const std::string& hanSuDung, const std::string& loaiNuoc);
    void inThongTin() const override;
};

// Lớp con cho rau củ
class RauCu : public SanPham {
private:
    std::string loaiRauCu;

public:
    RauCu(const std::string& ten, int soLuong, const std::string& ngaySanXuat, const std::string& hanSuDung, const std::string& loaiRauCu);
    void inThongTin() const override;
};

// Lớp con cho gia vị
class GiaVi : public SanPham {
private:
    std::string loaiGiaVi;

public:
    GiaVi(const std::string& ten, int soLuong, const std::string& ngaySanXuat, const std::string& hanSuDung, const std::string& loaiGiaVi);
    void inThongTin() const override;
};

// Lớp con cho bánh
class Banh : public SanPham {
private:
    std::string loaiBanh;

public:
    Banh(const std::string& ten, int soLuong, const std::string& ngaySanXuat, const std::string& hanSuDung, const std::string& loaiBanh);
    void inThongTin() const override;
};

// Lớp con cho giấy
class Giay : public SanPham {
private:
    std::string loaiGiay;

public:
    Giay(const std::string& ten, int soLuong, const std::string& ngaySanXuat, const std::string& hanSuDung, const std::string& loaiGiay);
    void inThongTin() const override;
};

// Lớp con cho chén bát
class ChenBat : public SanPham {
private:
    std::string loaiChenBat;

public:
    ChenBat(const std::string& ten, int soLuong, const std::string& ngaySanXuat, const std::string& hanSuDung, const std::string& loaiChenBat);
    void inThongTin() const override;
};

// Lớp con cho đồ đóng hộp
class DoDongHop : public SanPham {
private:
    std::string loaiDoDongHop;

public:
    DoDongHop(const std::string& ten, int soLuong, const std::string& ngaySanXuat, const std::string& hanSuDung, const std::string& loaiDoDongHop);
    void inThongTin() const override;
};

// Hàm đọc sản phẩm từ file
void docTuFile(const std::string& tenFile, std::vector<SanPham*>& danhSachSanPham);



// Khai báo constructor cho lớp SanPham
SanPham::SanPham(const std::string& ten, int soLuong, const std::string& ngaySanXuat, const std::string& hanSuDung) 
    : ten(ten), soLuong(soLuong), ngaySanXuat(ngaySanXuat), hanSuDung(hanSuDung) {}

// Phương thức in thông tin cho lớp SanPham
void SanPham::inThongTin() const {
    std::cout << "Tên sản phẩm: " << ten << "\n"
              << "Số lượng: " << soLuong << "\n"
              << "Ngày sản xuất: " << ngaySanXuat << "\n"
              << "Hạn sử dụng: " << hanSuDung << "\n";
}

// Phương thức thêm sản phẩm
void SanPham::themSanPham(int soLuong) {
    this->soLuong += soLuong;
}

// Phương thức bán sản phẩm
bool SanPham::banSanPham(int soLuong) {
    if (this->soLuong >= soLuong) {
        this->soLuong -= soLuong;
        return true;
    } else {
        std::cout << "Không đủ sản phẩm để bán!\n";
        return false;
    }
}

// Khai báo constructor cho lớp Thit
Thit::Thit(const std::string& ten, int soLuong, const std::string& ngaySanXuat, const std::string& hanSuDung, const std::string& loaiThit) 
    : SanPham(ten, soLuong, ngaySanXuat, hanSuDung), loaiThit(loaiThit) {}

// Phương thức in thông tin cho lớp Thit
void Thit::inThongTin() const {
    SanPham::inThongTin();
    std::cout << "Loại thịt: " << loaiThit << "\n";
}

// Khai báo constructor cho lớp Ca
Ca::Ca(const std::string& ten, int soLuong, const std::string& ngaySanXuat, const std::string& hanSuDung, const std::string& loaiCa) 
    : SanPham(ten, soLuong, ngaySanXuat, hanSuDung), loaiCa(loaiCa) {}

// Phương thức in thông tin cho lớp Ca
void Ca::inThongTin() const {
    SanPham::inThongTin();
    std::cout << "Loại cá: " << loaiCa << "\n";
}

// Khai báo constructor cho lớp Keo
Keo::Keo(const std::string& ten, int soLuong, const std::string& ngaySanXuat, const std::string& hanSuDung, const std::string& loaiKeo) 
    : SanPham(ten, soLuong, ngaySanXuat, hanSuDung), loaiKeo(loaiKeo) {}

// Phương thức in thông tin cho lớp Keo
void Keo::inThongTin() const {
    SanPham::inThongTin();
    std::cout << "Loại kẹo: " << loaiKeo << "\n";
}

// Khai báo constructor cho lớp Nuoc
Nuoc::Nuoc(const std::string& ten, int soLuong, const std::string& ngaySanXuat, const std::string& hanSuDung, const std::string& loaiNuoc) 
    : SanPham(ten, soLuong, ngaySanXuat, hanSuDung), loaiNuoc(loaiNuoc) {}

// Phương thức in thông tin cho lớp Nuoc
void Nuoc::inThongTin() const {
    SanPham::inThongTin();
    std::cout << "Loại nước: " << loaiNuoc << "\n";
}

// Khai báo constructor cho lớp RauCu
RauCu::RauCu(const std::string& ten, int soLuong, const std::string& ngaySanXuat, const std::string& hanSuDung, const std::string& loaiRauCu) 
    : SanPham(ten, soLuong, ngaySanXuat, hanSuDung), loaiRauCu(loaiRauCu) {}

// Phương thức in thông tin cho lớp RauCu
void RauCu::inThongTin() const {
    SanPham::inThongTin();
    std::cout << "Loại rau củ: " << loaiRauCu << "\n";
}

// Khai báo constructor cho lớp GiaVi
GiaVi::GiaVi(const std::string& ten, int soLuong, const std::string& ngaySanXuat, const std::string& hanSuDung, const std::string& loaiGiaVi) 
    : SanPham(ten, soLuong, ngaySanXuat, hanSuDung), loaiGiaVi(loaiGiaVi) {}

// Phương thức in thông tin cho lớp GiaVi
void GiaVi::inThongTin() const {
    SanPham::inThongTin();
    std::cout << "Loại gia vị: " << loaiGiaVi << "\n";
}

// Khai báo constructor cho lớp Banh
Banh::Banh(const std::string& ten, int soLuong, const std::string& ngaySanXuat, const std::string& hanSuDung, const std::string& loaiBanh) 
    : SanPham(ten, soLuong, ngaySanXuat, hanSuDung), loaiBanh(loaiBanh) {}

// Phương thức in thông tin cho lớp Banh
void Banh::inThongTin() const {
    SanPham::inThongTin();
    std::cout << "Loại bánh: " << loaiBanh << "\n";
}

// Khai báo constructor cho lớp Giay
Giay::Giay(const std::string& ten, int soLuong, const std::string& ngaySanXuat, const std::string& hanSuDung, const std::string& loaiGiay) 
    : SanPham(ten, soLuong, ngaySanXuat, hanSuDung), loaiGiay(loaiGiay) {}

// Phương thức in thông tin cho lớp Giay
void Giay::inThongTin() const {
    SanPham::inThongTin();
    std::cout << "Loại giấy: " << loaiGiay << "\n";
}

// Khai báo constructor cho lớp ChenBat
ChenBat::ChenBat(const std::string& ten, int soLuong, const std::string& ngaySanXuat, const std::string& hanSuDung, const std::string& loaiChenBat) 
    : SanPham(ten, soLuong, ngaySanXuat, hanSuDung), loaiChenBat(loaiChenBat) {}

// Phương thức in thông tin cho lớp ChenBat
void ChenBat::inThongTin() const {
    SanPham::inThongTin();
    std::cout << "Loại chén bát: " << loaiChenBat << "\n";
}

// Khai báo constructor cho lớp DoDongHop
DoDongHop::DoDongHop(const std::string& ten, int soLuong, const std::string& ngaySanXuat, const std::string& hanSuDung, const std::string& loaiDoDongHop) 
    : SanPham(ten, soLuong, ngaySanXuat, hanSuDung), loaiDoDongHop(loaiDoDongHop) {}

// Phương thức in thông tin cho lớp DoDongHop
void DoDongHop::inThongTin() const {
    SanPham::inThongTin();
    std::cout << "Loại đồ đóng hộp: " << loaiDoDongHop << "\n";
}

// Hàm đọc sản phẩm từ file
void docTuFile(const std::string& tenFile, std::vector<SanPham*>& danhSachSanPham) {
    std::ifstream file(tenFile);
    if (!file.is_open()) {
        std::cerr << "Không thể mở file: " << tenFile << std::endl;
        return;
    }

    std::string ten, loai, ngaySanXuat, hanSuDung, loaiSanPham;
    int soLuong;

    while (file >> ten >> loai >> soLuong >> ngaySanXuat >> hanSuDung >> loaiSanPham) {
        if (loai == "thit") {
            if (loaiSanPham == "Heo") {
                danhSachSanPham.push_back(new Thit(ten, soLuong, ngaySanXuat, hanSuDung, loaiSanPham));
            } else if (loaiSanPham == "Bo") {
                danhSachSanPham.push_back(new Thit(ten, soLuong, ngaySanXuat, hanSuDung, loaiSanPham));
            }
        } else if (loai == "ca") {
            if (loaiSanPham == "Tram") {
                danhSachSanPham.push_back(new Ca(ten, soLuong, ngaySanXuat, hanSuDung, loaiSanPham));
            } else if (loaiSanPham == "RoPhi") {
                danhSachSanPham.push_back(new Ca(ten, soLuong, ngaySanXuat, hanSuDung, loaiSanPham));
            }
        } else if (loai == "keo") {
            if (loaiSanPham == "CaoSu") {
                danhSachSanPham.push_back(new Keo(ten, soLuong, ngaySanXuat, hanSuDung, loaiSanPham));
            } else if (loaiSanPham == "Anphalibe") {
                danhSachSanPham.push_back(new Keo(ten, soLuong, ngaySanXuat, hanSuDung, loaiSanPham));
            }
        } else if (loai == "nuoc") {
            danhSachSanPham.push_back(new Nuoc(ten, soLuong, ngaySanXuat, hanSuDung, loaiSanPham));
        } else if (loai == "raucu") {
            danhSachSanPham.push_back(new RauCu(ten, soLuong, ngaySanXuat, hanSuDung, loaiSanPham));
        } else if (loai == "gia") {
            danhSachSanPham.push_back(new GiaVi(ten, soLuong, ngaySanXuat, hanSuDung, loaiSanPham));
        } else if (loai == "banh") {
            danhSachSanPham.push_back(new Banh(ten, soLuong, ngaySanXuat, hanSuDung, loaiSanPham));
        } else if (loai == "giay") {
            danhSachSanPham.push_back(new Giay(ten, soLuong, ngaySanXuat, hanSuDung, loaiSanPham));
        } else if (loai == "chenbat") {
            danhSachSanPham.push_back(new ChenBat(ten, soLuong, ngaySanXuat, hanSuDung, loaiSanPham));
        } else if (loai == "dodonghop") {
            danhSachSanPham.push_back(new DoDongHop(ten, soLuong, ngaySanXuat, hanSuDung, loaiSanPham));
        }
    }

    file.close();
}



int main() {
    std::vector<SanPham*> danhSachSanPham;
    docTuFile("input.txt", danhSachSanPham);

    // Hiển thị thông tin sản phẩm
    for (const auto& sanPham : danhSachSanPham) {
        sanPham->inThongTin();
        std::cout << "--------------------------\n";
    }

    // Thêm sản phẩm
    if (!danhSachSanPham.empty()) {
        danhSachSanPham[0]->themSanPham(10); // Thêm 10 sản phẩm vào sản phẩm đầu tiên
        std::cout << "Sau khi thêm:\n";
        danhSachSanPham[0]->inThongTin();
    }

    // Bán sản phẩm
    if (!danhSachSanPham.empty()) {
        if (danhSachSanPham[0]->banSanPham(5)) {
            std::cout << "Đã bán 5 sản phẩm.\n";
        }
        std::cout << "Sau khi bán:\n";
        danhSachSanPham[0]->inThongTin();
    }

    // Giải phóng bộ nhớ
    for (auto& sanPham : danhSachSanPham) {
        delete sanPham;
    }

	std::cout << "kho nói";

    return 0;
}

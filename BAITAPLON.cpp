#include <iostream>
#include <string>
using namespace std;
struct Thuoc {
    string ma;
    string ten;
    float gia;
    Thuoc* next;
    Thuoc* prev;
};
// 1. Them vao dau danh sach
Thuoc* themVaoDau(Thuoc* &head, string ma, string ten, float gia) {
    Thuoc* pDrug = new Thuoc;
    pDrug->ma = ma;
    pDrug->ten = ten;
    pDrug->gia = gia;
    pDrug->next = head;
    pDrug->prev = NULL;
    if (head != NULL) {
        head->prev = pDrug;
    }
    head = pDrug;
    return head;
}

// 2. Them thuoc vao giua danh sach
Thuoc* themVaoGiua(Thuoc* &head, string ma, string ten, float gia, int position) {
    if (position == 0) {
        return themVaoDau(head, ma, ten, gia);
    }

    Thuoc* pDrug = new Thuoc;
    pDrug->ma = ma;
    pDrug->ten = ten;
    pDrug->gia = gia;
    pDrug->next = NULL;
    pDrug->prev = NULL;

    Thuoc* pCur = head;
    for (int i = 0; i < position - 1 && pCur != NULL; i++) {
        pCur = pCur->next;
    }
    if (pCur == NULL) {
        cout << "Vi tri khong hop le.\n";
        delete pDrug;
    } else {
        pDrug->next = pCur->next;
        pDrug->prev = pCur;
        if (pCur->next != NULL) {
            pCur->next->prev = pDrug;
        }
        pCur->next = pDrug;
    }
    return head;
}

// 3. Them vao cuoi danh sach
Thuoc* chenVaoCuoi(Thuoc* &head, string ma, string ten, float gia) {
    Thuoc* pDrug = new Thuoc;
    pDrug->ma = ma;
    pDrug->ten = ten;
    pDrug->gia = gia;
    pDrug->next = NULL;

    if (head == NULL) {
        pDrug->prev = NULL;
        head = pDrug;
    } else {
        Thuoc* pCur = head;
        while (pCur->next != NULL) {
            pCur = pCur->next;
        }
        pCur->next = pDrug;
        pDrug->prev = pCur;
    }
    return head;
}

// 4. Xoa thuoc theo ma
Thuoc* xoaThuocTheoMa(Thuoc* &head, string maCanXoa) {
    Thuoc* pCur = head;

    while (pCur != NULL) {
        if (pCur->ma == maCanXoa) {
            if (pCur->prev != NULL) {
                pCur->prev->next = pCur->next;
            } else {
                head = pCur->next;
            }
            if (pCur->next != NULL) {
                pCur->next->prev = pCur->prev;
            }
            delete pCur;
            return head;
        }
        pCur = pCur->next;
    }

    cout << "Khong tim thay thuoc co ma " << maCanXoa << " can xoa.\n";
    return head;
}

// 5. Hien thi danh sach thuoc
void hienThiDanhSach(Thuoc* head) {
    Thuoc* pCur = head;
    cout << "Danh sach thuoc:\n";
    while (pCur != NULL) {
        cout << "Ma: " << pCur->ma << ", Ten: " << pCur->ten << ", Gia: " << pCur->gia << endl;
        pCur = pCur->next;
    }
}

// 6. Sua thong tin thuoc
void suaThongTinThuoc(Thuoc* &head, string ma, string tenMoi, float giaMoi) {
    Thuoc* pCur = head;
    while (pCur != NULL) {
        if (pCur->ma == ma) {
            pCur->ten = tenMoi;
            pCur->gia = giaMoi;
            cout << "Da sua thong tin thuoc co ma " << ma << endl;
            return;
        }
        pCur = pCur->next;
    }
    cout << "Khong tim thay thuoc co ma " << ma << " can sua.\n";
}

// 7. Dem so luong thuoc
int demSoLuongThuoc(Thuoc* head) {
    int count = 0;
    Thuoc* pCur = head;
    while (pCur != NULL) {
        count++;
        pCur = pCur->next;
    }
    return count;
}

// 8. Tim thuoc co gia cao nhat
Thuoc* timThuocGiaCaoNhat(Thuoc* head) {
    if (head == NULL) return NULL;
    Thuoc* maxGia = head;
    Thuoc* pCur = head->next;
    while (pCur != NULL) {
        if (pCur->gia > maxGia->gia) {
            maxGia = pCur;
        }
        pCur = pCur->next;
    }
    return maxGia;
}

// 9. Tim thuoc co gia thap nhat
Thuoc* timThuocGiaThapNhat(Thuoc* head) {
    if (head == NULL) return NULL;
    Thuoc* minGia = head;
    Thuoc* pCur = head->next;
    while (pCur != NULL) {
        if (pCur->gia < minGia->gia) {
            minGia = pCur;
        }
        pCur = pCur->next;
    }
    return minGia;
}

// 10. Tinh tong gia tri cua cac loai thuoc
float tongGiaTriThuoc(Thuoc* head) {
    float tongGia = 0;
    Thuoc* pCur = head;
    while (pCur != NULL) {
        tongGia += pCur->gia;
        pCur = pCur->next;
    }
    return tongGia;
}

// 11. Tim thuoc theo ten
Thuoc* timThuocTheoTen(Thuoc* head, string ten) {
    Thuoc* pCur = head;
    while (pCur != NULL) {
        if (pCur->ten == ten) {
            return pCur;
        }
        pCur = pCur->next;
    }
    return NULL;
}
// 12. Sap xep danh sach thuoc theo gia tang dan
void sapXepThuocTheoGiaTangDan(Thuoc* &head) {
    if (head == NULL) return;
    Thuoc* pCur = head;
    while (pCur != NULL) {
        Thuoc* pMin = pCur;
        Thuoc* pSearch = pCur->next;
        while (pSearch != NULL) {
            if (pSearch->gia < pMin->gia) {
                pMin = pSearch;
            }
            pSearch = pSearch->next;
        }
        if (pMin != pCur) {
            swap(pCur->ma, pMin->ma);
            swap(pCur->ten, pMin->ten);
            swap(pCur->gia, pMin->gia);
        }
        pCur = pCur->next;
    }
}

// 13. Sap xep danh sach thuoc theo gia giam dan
void sapXepThuocTheoGiaGiamDan(Thuoc* &head) {
    if (head == NULL) return;
    Thuoc* pCur = head;
    while (pCur != NULL) {
        Thuoc* pMax = pCur;
        Thuoc* pSearch = pCur->next;
        while (pSearch != NULL) {
            if (pSearch->gia > pMax->gia) {
                pMax = pSearch;
            }
            pSearch = pSearch->next;
        }
        if (pMax != pCur) {
            swap(pCur->ma, pMax->ma);
            swap(pCur->ten, pMax->ten);
            swap(pCur->gia, pMax->gia);
        }
        pCur = pCur->next;
    }
}

// 14. Tim thuoc co gia trong mot khoang cho truoc
void timThuocTrongKhoangGia(Thuoc* head, float giaMin, float giaMax) {
    bool found = false;
    Thuoc* pCur = head;
    cout << "Cac thuoc co gia trong khoang tu " << giaMin << " den " << giaMax << ":\n";
    while (pCur != NULL) {
        if (pCur->gia >= giaMin && pCur->gia <= giaMax) {
            cout << "Ma: " << pCur->ma << ", Ten: " << pCur->ten << ", Gia: " << pCur->gia << endl;
            found = true;
        }
        pCur = pCur->next;
    }
    if (!found) {
        cout << "Khong tim thay thuoc nao trong khoang gia nay.\n";
    }
}

// 15. Kiem tra danh sach co rong hay khong
bool kiemTraDanhSachRong(Thuoc* head) {
    return head == NULL;
}

// 16. Tim thuoc co ten bat dau bang chuoi cho truoc
void timThuocBatDauBangChuoi(Thuoc* head, string chuoi) {
    bool found = false;
    Thuoc* pCur = head;
    cout << "Cac thuoc co ten bat dau bang chuoi \"" << chuoi << "\":\n";
    while (pCur != NULL) {
        if (pCur->ten.find(chuoi) == 0) {
            cout << "Ma: " << pCur->ma << ", Ten: " << pCur->ten << ", Gia: " << pCur->gia << endl;
            found = true;
        }
        pCur = pCur->next;
    }
    if (!found) {
        cout << "Khong tim thay thuoc nao co ten bat dau bang chuoi nay.\n";
    }
}

// 17. Tim thuoc co ten ket thuc bang chuoi cho truoc
void timThuocKetThucBangChuoi(Thuoc* head, string chuoi) {
    bool found = false;
    Thuoc* pCur = head;
    cout << "Cac thuoc co ten ket thuc bang chuoi \"" << chuoi << "\":\n";
    while (pCur != NULL) {
        if (pCur->ten.rfind(chuoi) == pCur->ten.length() - chuoi.length()) {
            cout << "Ma: " << pCur->ma << ", Ten: " << pCur->ten << ", Gia: " << pCur->gia << endl;
            found = true;
        }
        pCur = pCur->next;
    }
    if (!found) {
        cout << "Khong tim thay thuoc nao co ten ket thuc bang chuoi nay.\n";
    }
}

// 18. Thong ke so luong thuoc co gia cao hon mot muc gia cho truoc
int thongKeSoLuongThuocGiaCaoHon(Thuoc* head, float mucGia) {
    int count = 0;
    Thuoc* pCur = head;
    while (pCur != NULL) {
        if (pCur->gia > mucGia) {
            count++;
        }
        pCur = pCur->next;
    }
    return count;
}

// 19. Tao ban sao cua danh sach
Thuoc* saoChepDanhSach(Thuoc* head) {
    if (head == NULL) return NULL;
    Thuoc* newHead = NULL;
    Thuoc* pCur = head;
    while (pCur != NULL) {
        newHead = chenVaoCuoi(newHead, pCur->ma, pCur->ten, pCur->gia);
        pCur = pCur->next;
    }
    return newHead;
}

// 20. Tao ban sao cua mot thuoc
Thuoc* taoBanSaoThuoc(Thuoc* head, string ma) {
    Thuoc* pCur = head;
    while (pCur != NULL) {
        if (pCur->ma == ma) {
            Thuoc* pBanSao = new Thuoc;
            pBanSao->ma = pCur->ma;
            pBanSao->ten = pCur->ten;
            pBanSao->gia = pCur->gia;
            pBanSao->next = NULL;
            pBanSao->prev = NULL;
            return pBanSao;
        }
        pCur = pCur->next;
    }
    return NULL;
}

// 21. Them thuoc vao sau mot thuoc cho truoc
void themThuocSauThuocKhac(Thuoc* &head, string maSau, string ma, string ten, float gia) {
    Thuoc* pCur = head;
    while (pCur != NULL) {
        if (pCur->ma == maSau) {
            Thuoc* pThuocMoi = new Thuoc;
            pThuocMoi->ma = ma;
            pThuocMoi->ten = ten;
            pThuocMoi->gia = gia;
            pThuocMoi->next = pCur->next;
            pThuocMoi->prev = pCur;
            if (pCur->next != NULL) {
                pCur->next->prev = pThuocMoi;
            }
            pCur->next = pThuocMoi;
            return;
        }
        pCur = pCur->next;
    }
    cout << "Khong tim thay thuoc co ma " << maSau << " de them sau.\n";
}

// 22. Dao nguoc danh sach thuoc
Thuoc* daoNguocDanhSach(Thuoc* &head) {
    Thuoc* pCur = head;
    Thuoc* pTemp = NULL;
    while (pCur != NULL) {
        pTemp = pCur->prev;
        pCur->prev = pCur->next;
        pCur->next = pTemp;
        pCur = pCur->prev;
    }
    if (pTemp != NULL) {
        head = pTemp->prev;
    }
    return head;
}

// 23. Hien thi danh sach thuoc co gia tri lon hon muc gia cho truoc
void hienThiThuocCoGiaLonHon(Thuoc* head, float mucGia) {
    bool found = false;
    Thuoc* pCur = head;
    cout << "Cac thuoc co gia lon hon " << mucGia << ":\n";
    while (pCur != NULL) {
        if (pCur->gia > mucGia) {
            cout << "Ma: " << pCur->ma << ", Ten: " << pCur->ten << ", Gia: " << pCur->gia << endl;
            found = true;
        }
        pCur = pCur->next;
    }
    if (!found) {
        cout << "Khong tim thay thuoc nao co gia lon hon muc gia nay.\n";
    }
}

// 24. Sua gia cua thuoc theo ma
void suaGiaThuocTheoMa(Thuoc* &head, string ma, float giaMoi) {
    Thuoc* pCur = head;
    while (pCur != NULL) {
        if (pCur->ma == ma) {
            pCur->gia = giaMoi;
            cout << "Da sua gia thuoc co ma " << ma << " thanh " << giaMoi << endl;
            return;
        }
        pCur = pCur->next;
    }
    cout << "Khong tim thay thuoc co ma " << ma << " de sua gia.\n";
}

// 25. Xoa toan bo danh sach
void xoaToanBoDanhSach(Thuoc* &head) {
    while (head != NULL) {
        Thuoc* pCur = head;
        head = head->next;
        delete pCur;
    }
}

int main() {
    Thuoc* danhSachThuoc = NULL;
    int chucNang;
    do {
        cout << "___________CAC CHUC NANG CUA CHUONG TRINH___________\n";
        cout << "1. Them vao dau danh sach\n";
        cout << "2. Them vao giua danh sach\n";
        cout << "3. Them vao cuoi danh sach\n";
        cout << "4. Xoa thuoc theo ma\n";
        cout << "5. Hien thi danh sach thuoc\n";
        cout << "6. Sua thong tin thuoc\n";
        cout << "7. Dem so luong thuoc\n";
        cout << "8. Tim thuoc co gia cao nhat\n";
        cout << "9. Tim thuoc co gia thap nhat\n";
        cout << "10. Tinh tong gia tri cua cac loai thuoc\n";
        cout << "11. Tim thuoc theo ten\n";
        cout << "12. Sap xep danh sach thuoc theo gia tang dan\n";
        cout << "13. Sap xep danh sach thuoc theo gia giam dan\n";
        cout << "14. Tim thuoc co gia trong mot khoang cho truoc\n";
        cout << "15. Kiem tra danh sach co rong hay khong\n";
        cout << "16. Tim thuoc co ten bat dau bang chuoi cho truoc\n";
        cout << "17. Tim thuoc co ten ket thuc bang chuoi cho truoc\n";
        cout << "18. Thong ke so luong thuoc co gia cao hon mot muc gia cho truoc\n";
        cout << "19. Tao ban sao cua danh sach\n";
        cout << "20. Tao ban sao cua mot thuoc\n";
        cout << "21. Them thuoc vao sau mot thuoc cho truoc\n";
        cout << "22. Dao nguoc danh sach thuoc\n";
        cout << "23. Hien thi danh sach thuoc co gia tri lon hon muc gia cho truoc\n";
        cout << "24. Sua gia cua thuoc theo ma\n";
        cout << "25. Thoat\n";
        cout << "Nhap lua chon cua ban: ";
        cin >> chucNang;

        switch (chucNang) {
            case 1: {
                string ma, ten;
                float gia;
                cout << "Nhap ma thuoc: ";
                cin >> ma;
                cout << "Nhap ten thuoc: ";
                cin >> ten;
                cout << "Nhap gia thuoc: ";
                cin >> gia;
                themVaoDau(danhSachThuoc, ma, ten, gia);
                break;
            }
            case 2: {
                string ma, ten;
                float gia;
                int position;
                cout << "Nhap ma thuoc: ";
                cin >> ma;
                cout << "Nhap ten thuoc: ";
                cin >> ten;
                cout << "Nhap gia thuoc: ";
                cin >> gia;
                cout << "Nhap vi tri can chen: ";
                cin >> position;
                themVaoGiua(danhSachThuoc, ma, ten, gia, position);
                break;
            }
            case 3: {
                string ma, ten;
                float gia;
                cout << "Nhap ma thuoc: ";
                cin >> ma;
                cout << "Nhap ten thuoc: ";
                cin >> ten;
                cout << "Nhap gia thuoc: ";
                cin >> gia;
                chenVaoCuoi(danhSachThuoc, ma, ten, gia);
                break;
            }
            case 4: {
                string ma;
                cout << "Nhap ma thuoc can xoa: ";
                cin >> ma;
                xoaThuocTheoMa(danhSachThuoc, ma);
                break;
            }
            case 5: {
                hienThiDanhSach(danhSachThuoc);
                break;
            }
            case 6: {
                string ma, tenMoi;
                float giaMoi;
                cout << "Nhap ma thuoc can sua: ";
                cin >> ma;
                cout << "Nhap ten moi: ";
                cin >> tenMoi;
                cout << "Nhap gia moi: ";
                cin >> giaMoi;
                suaThongTinThuoc(danhSachThuoc, ma, tenMoi, giaMoi);
                break;
            }
            case 7: {
                int soLuong = demSoLuongThuoc(danhSachThuoc);
                cout << "So luong thuoc: " << soLuong << endl;
                break;
            }
            case 8: {
                Thuoc* thuocMax = timThuocGiaCaoNhat(danhSachThuoc);
                if (thuocMax != NULL) {
                    cout << "Thuoc co gia cao nhat:\n";
                    cout << "Ma: " << thuocMax->ma << ", Ten: " << thuocMax->ten << ", Gia: " << thuocMax->gia << endl;
                } else {
                    cout << "Danh sach rong.\n";
                }
                break;
            }
            case 9: {
                Thuoc* thuocMin = timThuocGiaThapNhat(danhSachThuoc);
                if (thuocMin != NULL) {
                    cout << "Thuoc co gia thap nhat:\n";
                    cout << "Ma: " << thuocMin->ma << ", Ten: " << thuocMin->ten << ", Gia: " << thuocMin->gia << endl;
                } else {
                    cout << "Danh sach rong.\n";
                }
                break;
            }
            case 10: {
                float tongGia = tongGiaTriThuoc(danhSachThuoc);
                cout << "Tong gia tri cua cac loai thuoc: " << tongGia << endl;
                break;
            }
            case 11: {
                string ten;
                cout << "Nhap ten thuoc can tim: ";
                cin >> ten;
                Thuoc* thuocTimThay = timThuocTheoTen(danhSachThuoc, ten);
                if (thuocTimThay != NULL) {
                    cout << "Da tim thay thuoc:\n";
                    cout << "Ma: " << thuocTimThay->ma << ", Ten: " << thuocTimThay->ten << ", Gia: " << thuocTimThay->gia << endl;
                } else {
                    cout << "Khong tim thay thuoc co ten nay.\n";
                }
                break;
            }
            case 12: {
                sapXepThuocTheoGiaTangDan(danhSachThuoc);
                cout << "Da sap xep danh sach theo gia tang dan.\n";
                break;
            }
            case 13: {
                sapXepThuocTheoGiaGiamDan(danhSachThuoc);
                cout << "Da sap xep danh sach theo gia giam dan.\n";
                break;
            }
            case 14: {
                float giaMin, giaMax;
                cout << "Nhap gia tri thap nhat: ";
                cin >> giaMin;
                cout << "Nhap gia tri cao nhat: ";
                cin >> giaMax;
                timThuocTrongKhoangGia(danhSachThuoc, giaMin, giaMax);
                break;
            }
            case 15: {
                if (kiemTraDanhSachRong(danhSachThuoc)) {
                    cout << "Danh sach rong.\n";
                } else {
                    cout << "Danh sach khong rong.\n";
                }
                break;
            }
            case 16: {
                string chuoi;
                cout << "Nhap chuoi can tim: ";
                cin >> chuoi;
                timThuocBatDauBangChuoi(danhSachThuoc, chuoi);
                break;
            }
            case 17: {
                string chuoi;
                cout << "Nhap chuoi can tim: ";
                cin >> chuoi;
                timThuocKetThucBangChuoi(danhSachThuoc, chuoi);
                break;
            }
            case 18: {
                float mucGia;
                cout << "Nhap muc gia: ";
                cin >> mucGia;
                int soLuong = thongKeSoLuongThuocGiaCaoHon(danhSachThuoc, mucGia);
                cout << "So luong thuoc co gia cao hon " << mucGia << ": " << soLuong << endl;
                break;
            }
            case 19: {
                Thuoc* danhSachSaoChep = saoChepDanhSach(danhSachThuoc);
                cout << "Da tao ban sao cua danh sach.\n";
                hienThiDanhSach(danhSachSaoChep);
                xoaToanBoDanhSach(danhSachSaoChep);
                break;
            }
            case 20: {
                string ma;
                cout << "Nhap ma thuoc can tao ban sao: ";
                cin >> ma;
                Thuoc* thuocBanSao = taoBanSaoThuoc(danhSachThuoc, ma);
                if (thuocBanSao != NULL) {
                    cout << "Da tao ban sao cua thuoc:\n";
                    cout << "Ma: " << thuocBanSao->ma << ", Ten: " << thuocBanSao->ten << ", Gia: " << thuocBanSao->gia << endl;
                    delete thuocBanSao;
                } else {
                    cout << "Khong tim thay thuoc co ma nay.\n";
                }
                break;
            }
            case 21: {
                string maSau, ma, ten;
                float gia;
                cout << "Nhap ma thuoc sau do: ";
                cin >> maSau;
                cout << "Nhap ma thuoc: ";
                cin >> ma;
                cout << "Nhap ten thuoc: ";
                cin >> ten;
                cout << "Nhap gia thuoc: ";
                cin >> gia;
                themThuocSauThuocKhac(danhSachThuoc, maSau, ma, ten, gia);
                break;
            }
            case 22: {
                daoNguocDanhSach(danhSachThuoc);
                cout << "Da dao nguoc danh sach thuoc.\n";
                break;
            }
            case 23: {
                float mucGia;
                cout << "Nhap muc gia: ";
                cin >> mucGia;
                hienThiThuocCoGiaLonHon(danhSachThuoc, mucGia);
                break;
            }
            case 24: {
                string ma;
                float giaMoi;
                cout << "Nhap ma thuoc can sua gia: ";
                cin >> ma;
                cout << "Nhap gia moi: ";
                cin >> giaMoi;
                suaGiaThuocTheoMa(danhSachThuoc, ma, giaMoi);
                break;
            }
            case 25: {
                cout << "Thoat chuong trinh.\n";
                break;
            } 
            default: {
                cout << "Lua chon khong hop le. Vui long chon lai.\n";
                break;
            }
        }
    } while (chucNang != 25);

    // Xoa toan bo danh sach truoc khi thoat
    xoaToanBoDanhSach(danhSachThuoc);

    return 0;
}

